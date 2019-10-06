package main

import (
	"fmt"
	"runtime"
)

func main() {
	// uses 4 CPUs
	runtime.GOMAXPROCS(4)

	ch := make(chan int)
	go generate(ch)
	for {
		prime := <-ch
		fmt.Println(prime)
		ch1 := make(chan int)
		go filter(ch, ch1, prime)
		ch = ch1
	}
}

func generate(ch chan int) {
	for i := 2; ; i++ {
		ch <- i
	}
}

func filter(in, out chan int, prime int) {
	for {
		i := <-in
		if i%prime != 0 {
			out <- i
		}
	}
}
