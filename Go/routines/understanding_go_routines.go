// This is my favorite code snippet because it gave me a great understanding of go routines

package main

import (
	"fmt"
	"runtime"
	"sync"
	"time"
)

var wg sync.WaitGroup

// global duration constant, value of which controls the sleep time of `child` go routine
const duration  = 100

func main() {
	// Currently there is just one (main) routine running
	fmt.Println("In main function - ", runtime.NumGoroutine())

	// Lets spawn a new go routine, calling it `parent`
	wg.Add(1)
	go parentRoutine()

	// Let (main) routine wait for `parent` routine to complete
	wg.Wait()

	// Exit the (main) routine
	fmt.Println("Completed parent - ", runtime.NumGoroutine())
}

func parentRoutine() {
	fmt.Println("Starting parent function - ", runtime.NumGoroutine())

	// a shared result channel, of type int, between `parent` and `child` routines
	childRes := make(chan int)

	// `child` routine simply
	go func() {
		fmt.Println("Starting child function - ", runtime.NumGoroutine())
		time.Sleep(time.Duration(duration)*time.Second)
		fmt.Println("Child ended - ", runtime.NumGoroutine())
		childRes <- 1
	}()

	// `parent` routine has will now wait for 3 seconds
	// Within 3 seconds, if the `child` routine returns, then it prints "Child completed - 2" (Here 3 signifies number of active go routines)
	// Else it prints "Child timed out - 3" (Here 3 signifies number of active go routines)
	// Once `parent` routine returns, the `child` routine is a "zombie" routine
	select {
	case <-childRes:
		fmt.Println("Child completed - ", runtime.NumGoroutine())
	case <- time.After(time.Duration(3)*time.Second):
		fmt.Println("Child timed out - ", runtime.NumGoroutine())
	}

	// Release the waiting state on (main) routine
	wg.Done()
}
