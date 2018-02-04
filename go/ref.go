package main

import (
    "fmt"
    "reflect"
)

// https://gocn.io/question/54

var typeRegistry = make(map[string]reflect.Type)

// 根据类型名字生成
// Elem函数妙用
//reflect.New(elem)

func registerType(elem interface{}) {
    t := reflect.TypeOf(elem).Elem()
    typeRegistry[t.Name()] = t //根据类型的名字注册
}

func newStruct(name string) (interface{}, bool) {
    elem, ok := typeRegistry[name]
    if !ok {
        return nil, false
    }
    return reflect.New(elem).Elem().Interface(), true
}

func init() { // 这里是一个强制转换
    registerType((*test)(nil))
}

type test struct {
    Name string
    Sex  int
}

func main() {
    structName := "test"

    s, ok := newStruct(structName)
    if !ok {
        return
    }

    fmt.Println(s, reflect.TypeOf(s))

    t, ok := s.(test)
    if !ok {
        return
    }
    t.Name = "i am test"
    fmt.Println(t, reflect.TypeOf(t))
}
