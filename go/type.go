package main

import "fmt"
import "reflect"

type Foo struct {
  X string
  Y int
}

func (f Foo) do() {
  fmt.Printf("X is: %s, Y is: %d", f.X, f.Y)

}

func main() {
  var s string = "abc"
  fmt.Println(reflect.TypeOf(s).String()) //string
  fmt.Println(reflect.TypeOf(s).Name())   //string

  var f Foo
  typ := reflect.TypeOf(f)
  fmt.Println(typ.String()) //main.Foo
  fmt.Println(typ.Name())     //Foo ，返回结构体的名字
}

