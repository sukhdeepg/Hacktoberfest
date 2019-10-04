package main

import (
	"errors"
	"log"
	"net/http"
	"os"
)

var (
	StatusOk       = 200
	ErrorMessage   = "Something wrong with your website! :("
	SuccessMessage = "Your website is ok! :)"
)

/**
1. Run without arguments: go run simple_get_request.go
2. Run with arguments: go run simple_get_request.go https://github.com
*/
func main() {
	url := os.Args[1]
	if len(url) == 0 {
		url = "https://google.com"
	}
	resp, err := http.Get(url)
	if err != nil {
		log.Fatalln(err)
	}

	if resp.StatusCode != StatusOk {
		log.Fatalln(errors.New(ErrorMessage))
	} else {
		log.Print(SuccessMessage)
	}
}
