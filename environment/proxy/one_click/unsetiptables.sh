#!/bin/bash
CHAIN_NAME=REDSOCKS
#clear the rule under the chain REDSOCKS
sudo iptables -t nat -F $CHAIN_NAME
if [ $? -eq 1 ]; then
    echo "clear chain $CHAIN_NAME fail"
else
    echo "clear chain $CHAIN_NAME success"
fi
