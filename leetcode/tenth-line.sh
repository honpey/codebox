#!/bin/bash

count=0
while read line
do	
	let count++
	if [ $count = 10 ]; then
		echo $line
		exit
	fi

done < file.txt

echo ""
