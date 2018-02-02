package main

import "fmt"

func main() {
	var mapp map[string]int
	mapp = make(map[string]int, 100)
	mapp["hello"]=1
	mapp["world"]=2
	fmt.Println("hello world")
	fmt.Println(mapp)
}
