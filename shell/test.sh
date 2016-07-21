#!/bin/bash

funa()
{
	echo "this is 00279156"
	echo "funa"
}
funb()
{
	echo "this is 00279156"
	echo "funb"
}

if [ "$1" = "f2fs" ]; then
	echo "f2fs"
else
	echo "ext4"
fi

if [ $1 = 2 ]; then
	echo "your input is 2"
fi

if [ $1 = 3 ]; then
	echo "your input is 3"
fi
