package main

import (
    "fmt"
    "runtime"
)

func main() {
    fmt.Print("%s", runtime.Version())
}
