package main

import (
    "fmt"
    "os"
)

func main() {
    fmt.Printf("%s\n", "hello")
    file, err := os.Create("./res")
    if err != nil {
        fmt.Print("Fail to crete file")
        return 
    }
    var hi string
    hi = "hwllo wrold"
    file.WriteString(hi+"\n")
    file.WriteString(hi)
}
