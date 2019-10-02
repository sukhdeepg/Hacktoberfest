package cleave

func Primes(n int) []int {
	// make list
	numbers := make(map[int]struct{})

	for i := 2; i < n; i++ {
		numbers[i] = struct{}{}
	}

	p := 2
	for {
		for q := 2 * p; q < n; q = q + p {
			delete(numbers, q)
		}
		if p >= n {
			break
		}
		p = p + 1
	}

	returnSlice := make([]int, 0)
	for key := range numbers {
		returnSlice = append(returnSlice, key)
	}

	return returnSlice

}
