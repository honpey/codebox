#!/bin/bash

#  C语言中经常会有这样的函数头
#  	void __iomem		*regs;
#   #define FMODE_PATH		((__force fmode_t)0x4000)
#   extern int vfs_lstat(const char __user *, struct kstat *);

#   这些__force,__iomem,__user并无实际的用途,仅仅是为了给用户提示而已

echo $#
echo $@
echo $1 $3

count=0
archs="arm64 x86 arm ppc"
for arch in ${archs}; do
	let count++
	case ${arch} in
	"arm64")	#
		echo $count
		echo "arm64"
		;;
	"x86")
		echo $count
		echo "x86"
		;;
	"arm")
		echo $count
		echo "arm"
		;;
	"ppc")
		echo $count
		echo "ppc"
		;;
	esac
done




