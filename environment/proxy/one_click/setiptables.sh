#!/bin/bash
CHAIN_NAME=REDSOCKS
USER_NAME=`whoami`
#the port will be used in the redsocks config file
#:redsocks.local_port, make sure they are same
PORT=12345
echo "username $USER_NAME"
echo "local proxy to port $PORT, should be same as the value redsocks.local_port in redsocks config file"
#clear the rule under the chain REDSOCKS
sudo iptables -t nat -F $CHAIN_NAME
if [ $? -eq 1 ]; then
    echo "create new chain $CHAIN_NAME"
    sudo iptables -t nat -N $CHAIN_NAME
else
    echo "clear $CHAIN_NAME"
fi
#
sudo iptables -t nat -A $CHAIN_NAME -d 0.0.0.0/8 -j RETURN
sudo iptables -t nat -A $CHAIN_NAME -d 10.0.0.0/8 -j RETURN
sudo iptables -t nat -A $CHAIN_NAME -d 127.0.0.0/8 -j RETURN
sudo iptables -t nat -A $CHAIN_NAME -d 169.254.0.0/16 -j RETURN
sudo iptables -t nat -A $CHAIN_NAME -d 172.16.0.0/12 -j RETURN
sudo iptables -t nat -A $CHAIN_NAME -d 192.168.0.0/16 -j RETURN
sudo iptables -t nat -A $CHAIN_NAME -d 224.0.0.0/4 -j RETURN
sudo iptables -t nat -A $CHAIN_NAME -d 240.0.0.0/4 -j RETURN
sudo iptables -t nat -A $CHAIN_NAME -p tcp -j REDIRECT --to-ports $PORT
sudo iptables -t nat -A OUTPUT -p tcp -m owner --uid-owner $USER_NAME -j $CHAIN_NAME
if [ $? -eq 0 ]; then
    echo "config iptables success, try to start redsocks"
fi

./redsocks -c ./redsocks.conf
