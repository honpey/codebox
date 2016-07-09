#!/bin/bash

# calculate the frequcy of work in one file
declare -A countABC
while read line
do
	for word in $line
	do
		let countABC[${word}]++;

	done

done < ./words.txt

func () {
	for i in ${!countABC[*]}
	do
		echo "$i ${countABC[$i]}"

	done
}

func | sort -n -r -k 2 



