package main

import (
    "fmt"
    "regexp"
//    "strings"
)

func main() {
    reg := regexp.MustCompile("start.*\n")
    str := "00start12344567end\nstartbadcdddd123end\n\nstar-t1-23end\n"
    fmt.Println("Start")
    fmt.Print(str)
    fmt.Println("End")
    slice := reg.FindAllIndex([]byte(str), -1)
    for _, item := range slice {
 //       fileds := strings.Split(str[item[0]:item[1], ")
        fmt.Printf("%s", str[item[0]:item[1]])
    }

}
