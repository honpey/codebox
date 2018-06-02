package main

import (
    "fmt"
    "io/ioutil"
    "os"
)

func funca() {
    fmt.Printf("%s\n", "hello")
}

func main() {
    if len(os.Args) != 2 {
        fmt.Println("Fault")
        return
    }
    fmt.Printf("%s\n", "/proc/1/sched")
    data, _ := ioutil.ReadFile(os.Args[1])
    fmt.Print(string(data))

}
