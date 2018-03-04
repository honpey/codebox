package main

import "fmt"
import "github.com/docker/docker/daemon/caps"

func main() {
	elems := caps.GetAllCapabilities()
	for _, elem := range elems {
		fmt.Println(elem)
	}
}

