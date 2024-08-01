package everydaygo

import (
	"fmt"
	"strconv"
)

func calPoints(operations []string) int {
	ans := 0
	a := make([]int, 0, len(operations))
	for _, v := range operations {
		if v[0] == 'C' {
			ans -= a[len(a)-1]
			a = a[:len(a)-1]
		} else if v[0] == 'D' {
			ans += a[len(a)-1] * 2
			a = append(a, a[len(a)-1]*2)
		} else if v[0] == '+' {
			ans += a[len(a)-1] + a[len(a)-2]
			a = append(a, a[len(a)-1]+a[len(a)-2])
		} else {
			t, _ := strconv.Atoi(v)
			a = append(a, t)
			ans += t
		}
		fmt.Println(a, ans)
	}
	return ans
}
