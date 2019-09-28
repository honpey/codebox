package main

import (
    "fmt"
    "bufio"
    "os"
    "io"
)

func main() {
    file, err := os.Open("./hello")
    if err != nil {
        fmt.Println("Fail to open the input file")
            return
    }
    defer file.Close()
    br := bufio.NewReader(file)
    for {
        line, isPrefix, err1 := br.ReadLine()
        fmt.Printf("%s %b %s\n", line, isPrefix, err1)
        if err1 != nil && err1 == io.EOF {
            break
        }
    }

}
