package main

import "fmt"
import "lib/queue"
import "lib/tree"

func main() {
	fmt.Println("hello world")
	queue := queue.New()
	queue.PushBack(1)
	queue.PushBack(2)
	fmt.Println("1:", queue.PopBack())
	fmt.Println("2:", queue.PopBack())
	fmt.Println("2:", queue.PopBack())
	fmt.Println("2:", queue.PopBack())
	fmt.Println("2:", queue.PopBack())
	fmt.Println("2:", queue.PopBack())
	cbtree := tree.New()
	cbtree.AddChild(cbtree.Root, 1)
	cbtree.AddChild(cbtree.Root, 2)
	cbtree.PreOrderTraval(cbtree.Root, func(a interface{}){if val, ok := a.(int); ok {fmt.Printf("value: %d\n", val)}})
	fmt.Println(cbtree)
}
