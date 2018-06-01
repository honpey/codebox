package main
import (
    "fmt"
//    "os"
    "strconv"
    "reflect"
    )
func main() {
    var rel int
    var rel1 int64
    var err, err1 error

    rel1 = 12
    rel = 12
    rel1 = rel

    rel, err = strconv.Atoi("10000000")
    fmt.Printf("%d type:%s %s\n", rel, reflect.TypeOf(rel), err)
    rel1, err1 = strconv.ParseInt("10000000000000", 10, 64)
    fmt.Printf("%d type:%s %s\n", rel, reflect.TypeOf(rel1), err1)

    fmt.Printf("\n---------")
    fmt.Printf("%s\n", strconv.FormatInt((123), 8))
    fmt.Printf("%s\n", strconv.FormatInt((123), 10))
    fmt.Printf("%s\n", strconv.FormatInt((123), 16))
}
