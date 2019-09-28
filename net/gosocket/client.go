package main

import (
    "fmt"
    "net"
    "os"
)

func checkError(err error){
    if  err != nil {
        fmt.Println("Error: %s", err.Error())
        os.Exit(1)
    }
}

func main() {
    conn, err := net.Dial("tcp", "127.0.0.1:10000")
//    conn, err := net.Dial("tcp", "192.168.9.1:10000")
    checkError(err)
    defer conn.Close()

    conn.Write([]byte("Hello world!"))

    fmt.Println("send msg")
}
