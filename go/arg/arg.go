package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    fmt.Printf("%s\n", "hello")
    fmt.Printf("%d\n", len(os.Args))
    if len(os.Args) != 2 {
        fmt.Printf("bad Args\n")
        return
    }
    value, err := strconv.ParseInt(os.Args[1], 10, 64)
    fmt.Printf("arg2: %d, %s\n", value, err)
}
