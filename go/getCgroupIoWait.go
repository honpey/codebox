package main

import (
    "fmt"
    "io/ioutil"
    "strings"
    "strconv"
    "time"
    "path/filepath"
    "regexp"
    "os"
)

// e.g path=/sys/fs/cgroup/memory/test/tasks [1474 3923 2323 288 2332]
// return all the iowait info in tasks

func getCgroupIOWait(path string) int64 {
    // step1: get all the task pid from cgroup
    if _, err := os.Stat(path); os.IsNotExist(err) {
        return 0
    }
    data, err := ioutil.ReadFile(path)
    if err != nil {
        return 0
    }

    // step2: construct all the pid's /proc path
    fields := strings.Split(string(data), "\n")
    var paths []string
    for _, item := range fields {
        if item == "" {
            continue
        }
        tempPath := filepath.Join("/proc/", item, "sched")
        paths = append(paths, tempPath)
    }

    // step3: read the sched info from the /proc/<pid>/sched
    var allIoWait int64
    reg := regexp.MustCompile("se.statistics.iowait_sum.*\n")
    for _, item := range paths {
        schedInfo, err := ioutil.ReadFile(item)
        data := reg.Find([]byte(schedInfo))
//        fmt.Printf("iowait_sum: %s", string(data))
        fields := strings.Split(string(data), ":")
        if len(fields) != 2 {
            fmt.Printf("iowait_sum: %s", string(data))
            fmt.Printf("Wrong type: %d\n", len(fields))
            continue
        }
        iowaitF, err := strconv.ParseFloat(strings.TrimSpace(fields[1]), 64)
        if err != nil {
            continue
        }
        iowaitI := int64(iowaitF * 1000000)
        allIoWait = allIoWait + iowaitI
    }
    return allIoWait
}

func main() {
    var count int = 0
    var preIOWait int64
again:
    curIOWait := getCgroupIOWait("/sys/fs/cgroup/cpu/test/tasks")
    if count != 0 {
        fmt.Printf("%d\n", curIOWait - preIOWait)
        preIOWait = curIOWait
    }
    count = count + 1
    time.Sleep(3 * time.Second)
    goto again

}
