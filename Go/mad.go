package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(n uint64) uint64 {
	if n == 0 {
		return 1
	}
	if n <= 2 {
		return n
	}
	if n <= 4 {
		return 6
	}
	if n == 5 {
		return 3
	}
	return 9
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var t int
	fmt.Fscanf(reader, "%d\n", &t)

	for i := 0; i < t; i++ {
		var x uint64
		fmt.Fscanf(reader, "%d\n", &x)
		fmt.Fprintln(writer, solve(x))
	}
}
