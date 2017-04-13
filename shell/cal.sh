#!/bin/bash
start_addr=ffffffff812e0140
echo $start_addr
start_addr=$(echo $start_addr | tr '[:lower:]' '[:upper:]')
echo $start_addr

len=00000000000001A7

#stop_addr=$()

echo "obase=16;ibase=16;""$start_addr+$len" | bc
exit

for (( i=0;i<=20;i+=6 ))
do
  	echo "obase=16;ibase=16;$((16#$num_s + $i))"| bc
done
##!/bin/bash
#echo "0x12+0x12" | bc

