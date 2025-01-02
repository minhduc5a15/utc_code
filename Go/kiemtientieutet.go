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

	var n, q int
	fmt.Fscanf(reader, "%d %d\n", &n, &q)

	var l, r, s int
	var L, R int64 = 0, 0

	for i := 0; i < q; i++ {
		fmt.Fscanf(reader, "%d %d %d\n", &l, &r, &s)
		if l >= 1 && r < n {
			L += int64(s)
		}
		if l > 1 && r <= n {
			R += int64(s)
		}
	}

	if L > R {
		fmt.Fprintln(writer, L)
	} else {
		fmt.Fprintln(writer, R)
	}
}