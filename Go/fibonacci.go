package main

import "fmt"

func main() {

	fmt.Print(fibonacci(10)) // 55

}

// Fibonacci is a simple program to learn about recursion
func fibonacci(n int) int {
	if n < 1 {
		return 0
	} else if n < 3 {
		return 1
	}
	return fibonacci(n-1) + fibonacci(n-2)
}
