package main

import (
	"fmt"
	"sort"
)

func main() {
	var t int
	fmt.Scanln(&t)
	for t > 0 {
		t--
		var n int
		fmt.Scanln(&n)
		a := make([]int, n+1)
		for i := range n {
			fmt.Scanln(&a[i])
		}
		sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
		fmt.Println(a)
	}
}
