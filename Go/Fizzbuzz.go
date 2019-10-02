// Fizzbuzz is usually the first program I write in any language and it was fun learning how to do it in Go!
package main

import (
	"fmt"
	"strconv"
)

func main() {
	for i := 1; i <= 100; i++ {
		output := "";
		if i % 3 == 0 {
			output += "Fizz";
		}
		if i % 5 == 0 {
			output += "Buzz";
		}
		if output == "" {
			output = strconv.FormatInt(int64(i), 10)
		}
		fmt.Println(output);
	}
}
