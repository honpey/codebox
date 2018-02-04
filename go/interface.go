package main

import "fmt"
import "reflect"

type base interface {
	setName(name string)
}

type child1 struct {
	name string
}

type child2 struct {
	name string
}

func (c *child1) setName(name string) {
	c.name = name
	fmt.Println("child1")
}

func (c *child2) setName() {
	c.name = "xiaohong"
	fmt.Println("child2")
}

func main() {
	fmt.Println("hello world")
	var b base
	b = &child1 {
		name: "hello",
	}
	b.setName("nihao")
	fmt.Println("value", reflect.ValueOf(b))
	fmt.Println("type", reflect.TypeOf(b))
//	var a reflect.TypeOf(b)
//	if b.(child1) {
		fmt.Println("hello world")
		//fmt.Printf("%s\n", b.name)
//	}
}
