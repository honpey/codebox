package main

import (
    "fmt"
    "os"
)

func main() {
    fmt.Printf("%s\n", "hello")
    if _, err := os.Stat("./test"); os.IsNotExist(err) {
        fmt.Printf("%s\n", "No such file")
        fmt.Printf("%s\n", err)
    }

}
