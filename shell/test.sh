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

exit
while read line 
do
	echo $line" "$(($line))
done < ./num

if [[ $(echo "12.3>12.2" | bc) == 1 ]]
then
	echo "12 < 34"
fi

if [[ -e "$1" && "$1" == "f2fs" ]]
then
	echo "f2fs"
else
	echo "ext4"
fi

if [[ $1 = 2 ]]; then
	echo "your input is 2"
fi
exit

if [ $1 = 3 ]; then
	echo "your input is 3"
fi
