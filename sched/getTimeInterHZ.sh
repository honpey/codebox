#!/bin/bash

preCPU0=0
preCPU1=0
preTime=0
while true
do
    eval `cat /proc/interrupts | grep "timer interrupt" | awk '{print "curCPU0="$2" curCPU1="$3}'`
    curTime=`date +%s%N`
    diff0=$(($curCPU0-$preCPU0)) 
    diff1=$(($curCPU1-$preCPU1))
    timeDiff=$(($curTime-$preTime))
    echo "$timeDiff $diff0 $diff1"
    preCPU0=$curCPU0
    preCPU1=$curCPU1
    preTime=$curTime
    sleep 1

done
