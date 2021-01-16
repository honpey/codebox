package main
// 多路复用
import (
	"fmt"
	"github.com/hashicorp/yamux"
	"net"
	"time"
)

func Recv(stream net.Conn, id int){
	for {
		buf := make([]byte, 4)
		n, err := stream.Read(buf)
		if err == nil{
			fmt.Println("ID:", id, ", len:", n, time.Now().Unix(), string(buf))
		}else{
			fmt.Println(time.Now().Unix(), err)
			return
		}
	}
}
func main() {
	// 建立底层复用连接
	tcpaddr, _ := net.ResolveTCPAddr("tcp4", "127.0.0.1:8980");
	tcplisten, _ := net.ListenTCP("tcp", tcpaddr);
	conn, _ := tcplisten.Accept()
  // 这里的 conn 只要满足是一个 io.ReadWriteCloser 就可以了
	session, _ := yamux.Server(conn, nil)
  fmt.Println("start to listen....")
	id :=1
	for {
		// 建立多个流通路
    // 这里应该直接是用了异步 IO 的机制，所有的事情都是按照
		fmt.Println("start to listen")
		stream, err := session.Accept()
		if err == nil {
        fmt.Println("accept: %v", stream)
        id ++
			go Recv(stream, id)
		}else{
			fmt.Println("session over.")
			return
		}
	}

}

