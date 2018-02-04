package main

import "fmt"
import "reflect"

func GetMembers(i interface{}) {
	t := reflect.TypeOf(i)
	for {
		if t.Kind() == reflect.Struct {
			fmt.Printf("\n%-8v %v个字段:\n", t, t.NumField())
			for i := 0; i < t.NumField(); i++ {
				fmt.Println(t.Field(i).Name)
			}
		}
		fmt.Printf("\n%-8v %v 个方法:\n", t, t.NumMethod())
		for i := 0; i < t.NumMethod(); i++ {
			fmt.Println(t.Method(i).Name)
		}
		if t.Kind() == reflect.Ptr {
			t = t.Elem()
		} else {
			break
		}
	}
}

type sr struct {
	string
}

func (s sr) Read() {
}

func (s *sr) Write() {
}

type test struct {
	Name *string
}

func main() {
//	GetMembers((*test)(nil))
//	return

	var bb test
//	GetMembers(&sr{})
	tyt2 := reflect.ValueOf(bb).FieldByName("Name").Elem().CanSet()
//	tyt3 := reflect.ValueOf(&bb).FieldByName("Name").Elem().CanSet()
	tyt3 := int(1)
	fmt.Println("tyt", tyt2, " ", tyt3)
//	fmt.Println("tyt", reflect.TypeOf(reflect.Value(sr{}).Field
//	GetMembers(new(reflect.Type))
	return
	var a int = 10
//	var b int
	//怎么从 .reflect.Value. 类型中找到真正的类型
	// 反射类型和实际类型之间的转换
	// 关键
	b := reflect.New(reflect.ValueOf(a).Type()).Elem().Interface()
	c := reflect.New(reflect.TypeOf(a)).Elem().Interface()
	b1 := reflect.New(reflect.ValueOf(a).Type()).Elem()
	fmt.Println(reflect.TypeOf(b))
	fmt.Println(reflect.TypeOf(a))
	fmt.Println(reflect.TypeOf(c))
	fmt.Println(reflect.TypeOf(b1))
	/*
	_, ok := b.(int)
	if ok {
		fmt.Print("b: ", reflect.ValueOf(b))
		fmt.Println("\n")
//		fmt.Println("value \n", value)
	}
	*/
	//GetMembers(&src{])
}
