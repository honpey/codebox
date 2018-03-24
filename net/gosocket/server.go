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

func recvConnMsg(conn net.Conn) {
//  var buf [50]byte
    buf := make([]byte, 50)

    defer conn.Close()

    for {
        n, err := conn.Read(buf)

        if err != nil {
            fmt.Println("conn closed")
            return
        }

        //fmt.Println("recv msg:", buf[0:n])
        fmt.Println("recv msg:", string(buf[0:n]))
    }
}

func main() {
    listen_sock, err := net.Listen("tcp", "localhost:10000")
    checkError(err)
    defer listen_sock.Close()

    for {
        new_conn, err := listen_sock.Accept()
        if err != nil {
            continue
        }

        go recvConnMsg(new_conn)
    }

}
