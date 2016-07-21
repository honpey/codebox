#!/bin/bash
var1="hello world"
var2="nihao"
var3=1

func() {
	echo "hello this is my first function"
	echo $var1
}

func2() {
	echo "$1 $2"
	if (( $1 == 1 )); then
		echo "successful test"
	fi
}

func2 $var3 $var2

exit

while read line
do
	echo $line
done < info
return




if [[ "$var1" == "hello world" ]] 
then
	echo "cool, it is hello world"
fi

if [[ "$var3" == "1" ]]
then 
	echo "var3 is 1"
fi

if [ $var3 == 1 ]
then
	echo "basic numberic compare"
else
	echo "do not the same"
fi

if (( $var3 == 1 )) 
then
	echo "basic numberic compare"
else
	echo "do not the same"
fi
