#!/bin/bash

funa()
{
	echo "funa"
}
funb()
{
	echo "funb"
}
usage()
{
	echo "Usage of the shell\n"
}

if [ "$1" = "f2fs" ]; then
	echo "f2fs"
	funa
else
	echo "ext4"
	funb
fi
