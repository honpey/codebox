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
  var i int = 123
  var f = Foo{"abc", 123}
  var s = "abc"
  fmt.Println(reflect.ValueOf(i)) //<int Value>
  fmt.Println(reflect.ValueOf(f)) //<main.Foo Value>
  fmt.Println(reflect.ValueOf(s)) //abc

  //Value.String()方法对string类型的数据做了特殊处理，会直接返回字符串的值。
  //其它类型对象返回的格式都是"<Type% Value>"

}

