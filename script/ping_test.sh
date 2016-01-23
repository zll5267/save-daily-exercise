#!/bin/bash
begin=$1
end=$2

prefix_ip="192.168.0."

begin_ip=${begin:=0}
end_ip=${end:=254}
echo "begin_ip: $begin_ip, end_ip: $end_ip"

exist_ips=""

while [ $begin_ip -le $end_ip ];
do
   echo $begin_ip 
   #((begin_ip=$begin_ip+1))
   ((begin_ip++))
   if ping -c 1 $prefix_ip$begin_ip &> /dev/null; then
           echo $prefix_ip$begin_ip
   fi
done
