package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m, k int
	fmt.Fscan(reader, &n, &m, &k)

	arr := make([]int, k+2)
	arr[k+1] = n + 1

	l, r, curr := 0, 0, 0
	for i := 0; i < m; i++ {
		var x int
		fmt.Fscan(reader, &x)
		if x == 1 {
			curr--
		} else {
			curr++
		}
		if curr < l {
			l = curr
		}
		if curr > r {
			r = curr
		}
	}

	for i := 1; i <= k; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	res := 0
	for i := 1; i <= k+1; i++ {
		s := arr[i] - arr[i-1] - 1
		if s >= (r - l + 1) {
			res += s - (r - l + 1) + 1
		}
	}

	fmt.Fprintln(writer, res)
}