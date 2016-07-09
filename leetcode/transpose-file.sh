#!/bin/bash
newMaxLine=0
while read line 
do
	countInLine=-1
	for word in $line
	do
		let countInLine++
		count[$countInLine]=`echo "${count[$countInLine]} $word"`	
		if [ $countInLine -ge $newMaxLine ]; then
			newMaxLine=$countInLine
		fi
	done

done < ./file.txt

for i in `seq 0 $newMaxLine`
do
	echo ${count[$i]}
done
