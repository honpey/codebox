package main
// #cgo LDFLAGS: -ldl
// #include <dlfcn.h>
// #include <stdlib.h>
// #include <stdio.h>
// int
// bridge_func(void *f, char *key, char *cert, char **res)
// {
//   int (*newFunc) (char *, char *, char **);
//   newFunc = (int (*)(char *a, char *b, char **))f;
//   return newFunc(key, cert, res);
// }
// int
// bridge_func2(void *f, char *key, char *cert)
// {
//   int (*newFunc) (char *, char *);
//   newFunc = (int (*)(char *a, char *b))f;
//   return newFunc(key, cert);
// }

import "C"

import "fmt"

func main() {
  fmt.Println("hello world")
  handle := C.dlopen(C.CString("./liba.so"), C.RTLD_LAZY)
  funA := C.dlsym(handle, C.CString("merge2"))

  var str string
  a1 := "AAAA"
  b1 := "BBBB"
  //u := C.CString(str)

  fmt.Println("%v %v\n", handle, funA)
  for i := 0; i < 10; i++ {
    ret := C.bridge_func(funA, C.CString(a1), C.CString(b1))
    fmt.Printf("Result %v -> %v|\n", ret, str)
  }

  /*
  fmt.Println("%v %v\n", handle, funA)
  for i := 0; i < 10; i++ {
    ret := C.bridge_func(funA, C.CString(a1), C.CString(b1), &u)
    fmt.Printf("Result %v -> %v|\n", ret, str)
  }
  */
}
