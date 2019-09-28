#!/bin/bash

path1="/sys/fs/cgroup/cpu/test1"
path2="/sys/fs/cgroup/cpu/test2"

for item in `find $path1 -maxdepth 1 -type d`
do
    echo ${item}
    if [[ ${item} == ${path1} ]]; then
        echo "Attention: Skip current dir"
        continue
    fi
    cgPath=${item}
    cgPathShares=${cgPath}"/cpu.shares"
    cgPathPeriod=${cgPath}"/cpu.cfs_period_us"
    cgPathQuota=${cgPath}"/cpu.cfs_quota_us"
    echo "cgPathShares:${cgPathShares}"
    echo "cgPathPeriod:${cgPathPeriod}"
    shares=`cat ${cgPathShares}`
    period=`cat ${cgPathPeriod}`
    scale=$(($shares/1024*2))
    quota=$((${scale}*${period}))
    `echo ${quota} > ${cgPathQuota}`
done

for item in `find $path2 -maxdepth 1 -type d`
do
    echo ${item}
    if [[ ${item} == ${path2} ]]; then
        echo "Attention: Skip current dir"
        continue
    fi
    cgPath=${item}
    cgPathShares=${cgPath}"/cpu.shares"
    cgPathPeriod=${cgPath}"/cpu.cfs_period_us"
    cgPathQuota=${cgPath}"/cpu.cfs_quota_us"
    echo "cgPathShares:${cgPathShares}"
    echo "cgPathPeriod:${cgPathPeriod}"
    shares=`cat ${cgPathShares}`
    period=`cat ${cgPathPeriod}`
    scale=$(($shares/1024*2))
    quota=$((${scale}*${period}))
    `echo ${quota} > ${cgPathQuota}`
done
