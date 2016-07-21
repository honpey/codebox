#!/bin/bash

count=1
arch="arm64 x86 arm ppc"

do_command()
{
	if [ -f ./hi ]; then
		printf "Ignore arch:%s\n" ${arch}

	fi
}

# 删除掉所有的空行


for i in ${arch}
do
	let count++
	echo $i
	case $i in
	arm64)
		echo $count
		echo "arm64";;
	x86)
		echo $count
		echo "x86";;
	arm)
		echo $count
		echo "arm";;
	ppc)
		echo $count
		echo "ppc";;
	esac

done
