package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func isPrime(n int) bool {
	if n < 2 {
		return false
	}
	if n == 2 {
		return true
	}
	if n%2 == 0 {
		return false
	}
	for i := 3; i*i <= n; i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func solve(n int) int {
	if isPrime(n) {
		return 1
	}
	if n%2 == 0 || isPrime(n-2) {
		return 2
	}
	return 3
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	tStr, _ := reader.ReadString('\n')
	t, _ := strconv.Atoi(strings.TrimSpace(tStr))

	for i := 0; i < t; i++ {
		line, _ := reader.ReadString('\n')
		parts := strings.Fields(line)
		x, _ := strconv.Atoi(parts[0])
		n, _ := strconv.Atoi(parts[1])
		if n <= 3 && x > 0 {
			fmt.Fprintln(writer, "y 1")
			continue
		}
		res := solve(n)
		if res <= x {
			fmt.Fprintf(writer, "y %d\n", res)
		} else {
			fmt.Fprintln(writer, "n")
		}
	}
}
