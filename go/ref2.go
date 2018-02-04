package main

import(
    "fmt"
    "reflect"
)

type MyStruct struct{
    name string
}

func (this *MyStruct)GetName() string {
    return this.name
}

func main() {
    fmt.Println("--------------")
    var a MyStruct
    b := new(MyStruct)
    fmt.Println(reflect.ValueOf(a))
    fmt.Println(reflect.ValueOf(b))

    fmt.Println("--------------")
    a.name = "yejianfeng"
    b.name = "yejianfeng"
    val := reflect.ValueOf(a).FieldByName("name")

    //painc: val := reflect.ValueOf(b).FieldByName("name")
    fmt.Println(val)

    fmt.Println("--------------")
    fmt.Println(reflect.ValueOf(a).FieldByName("name").CanSet())
    fmt.Println(reflect.ValueOf(&(a.name)).Elem().CanSet())

    fmt.Println("--------------")
    var c string = "yejianfeng"
    p := reflect.ValueOf(&c)
    fmt.Println(p.CanSet())   //false
    fmt.Println(p.Elem().CanSet())  //true
    p.Elem().SetString("newName")
    fmt.Println(c)
}
