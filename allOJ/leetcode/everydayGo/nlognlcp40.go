package everydaygo

import (
	"fmt"
	"sort"
)

// func maxmiumScore(cards []int, cnt int) int {
func NmaxmiumScore(cards []int, cnt int) int {
	sort.Slice(cards, func(i, j int) bool { return cards[i] > cards[j] })
	odd := make([]int, 0, 5000)
	eve := make([]int, 0, 5000)
	flag := 0
	for _, v := range cards {
		if v&1 == 0 {
			eve = append(eve, v)
		} else {
			if flag == 0 {
				flag = v
			} else {
				odd = append(odd, v+flag)
				flag = 0
			}
		}
	}
	eve = append(eve, 0)
	ans := 0
	for i, j := 0, 0; i < len(odd) || j < len(eve)-1; {
		if i >= len(odd) { //如果单数被用完
			if cnt >= 1 && j < len(eve)-2 {
				fmt.Println(1, cnt, i, j)
				ans += eve[j]
				cnt--
				j++
				continue
			}
		} else if cnt >= 2 { //单数没有用完，注意考虑偶数不能直接用完【例如8,8,8,1,1 cnt = 4
			if j == len(eve)-2 || len(eve) == 1 || odd[i] >= eve[j]+eve[j+1] {
				fmt.Println(2, cnt, i, j)
				ans += odd[i]
				cnt -= 2
				i++
			} else if j < len(eve)-2 {
				fmt.Println(3, cnt, i, j)
				ans += eve[j]
				cnt--
				j++
			}
			continue
		}
		if cnt > 0 && len(eve)-2 >= j {
			fmt.Println(4, cnt, i, j)
			ans += eve[j]
			cnt--
		}
		if cnt != 0 {
			ans = 0
		}
		break
	}
	return ans
}
