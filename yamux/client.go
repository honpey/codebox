package main

import (
	"github.com/hashicorp/yamux"
	"net"
	"time"
)

func main()  {
	// 建立底层复用通道
	conn, _ := net.Dial("tcp", "127.0.0.1:8980")
	session, _ := yamux.Client(conn, nil)

	// create new session 1
	stream, _ := session.Open()
	stream.Write([]byte("ping" ))
	stream.Write([]byte("pnng" ))
	time.Sleep(1 * time.Second)

	// create new session 2
	stream1, _ := session.Open()
	stream1.Write([]byte("pong"))
	time.Sleep(1 * time.Second)

	stream2, _ := session.Open()
	stream2.Write([]byte("hello"))
	time.Sleep(1 * time.Second)

	// 清理退出
	time.Sleep(5 * time.Second)
	stream.Close()
	stream1.Close()
	session.Close()
	conn.Close()
}

