#!/bin/bash
pid=$1
pre=0
while true
do
	cur=`cat /proc/${pid}/status | grep VmRSS | awk '{print $2}'`
	((diff=cur-pre))
	pre=${cur}
	echo "${diff}KB"
	sleep 2
done
