package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func solve(s string, i int) int {
	nVal, _ := strconv.ParseUint(s, 10, 64)
	if nVal <= 1 {
		return int(nVal)
	}
	num1 := strings.Repeat("1", i)
	num1Val, _ := strconv.ParseUint(num1, 10, 64)
	res := int(nVal/num1Val) * i
	rem := nVal % num1Val
	remStr := strconv.FormatUint(rem, 10)
	num1MinusRem := strconv.FormatUint(num1Val-rem, 10)
	return res + int(math.Min(float64(solve(remStr, i-1)), float64(i+solve(num1MinusRem, i-1))))
}

func main() {
	var s string
	_, err := fmt.Scan(&s)
	if err != nil {
		return
	}
	fmt.Println(solve(s, len(s)+1))
}
