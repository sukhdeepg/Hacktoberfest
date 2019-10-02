package main

import (
	"log"
	"strconv"
)

func main() {

	col := 10
	row := 10
	rowResult := ""

	for i := 1; i <= row; i++ {
		for j := 1; j <= col; j++ {
			rowResult = rowResult + " " + strconv.Itoa(i*j)
		}
		log.Println(rowResult)
		rowResult = ""
	}
}
