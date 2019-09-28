package main

import (
    "fmt"
    "strings"
//    "io/ioutils"
)

func split(r rune) bool {
    if r == '\n' || r == ':' {
        return true
    }
    return false
}
func main() {
    fmt.Printf("%s\n", "hello")
    var testString string
    f := func (r rune) bool {
        if r == '\n' || r == ':' {
            return true
        }
        return false
    }
    testString = "123\n345\n788\n100\n"
    fields := strings.FieldsFunc(testString, f)
//    fields := strings.Split(testString, "\n")
    fmt.Printf("len:%d\n", len(fields))
    for _, item := range fields  {
        fmt.Printf("|%s|\n", item)
    }
    fmt.Print(fields)

}
