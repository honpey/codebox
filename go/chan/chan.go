package main
import "fmt"

func main() {
	processChan := make(chan int, 10)
	defer close(processChan)
	fmt.Println("hello world")
}
