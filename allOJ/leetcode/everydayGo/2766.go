package everydaygo

import (
	"fmt"
	"sort"
)

func relocateMarbles(nums []int, moveFrom []int, moveTo []int) []int {
	var id [200100]int //id[]对应原本下标
	var f [200100]bool
	var hashMap = make(map[int]int, 200100)
	a := append(nums, moveTo...)
	idx := 0
	for _, v := range a {
		_, e := hashMap[v]
		if !e {
			hashMap[v] = idx
			id[idx] = v
			f[idx] = false
			fmt.Println(idx, v)
			idx++
		}
	}

	//初始位置标记为有
	for _, v := range nums {
		f[hashMap[v]] = true
	}
	//移动石子
	for i, v := range moveFrom {
		f[hashMap[v]] = false
		f[hashMap[moveTo[i]]] = true
	}
	var ans []int
	for i, v := range f {
		if v {
			ans = append(ans, id[i])
		}
	}
	sort.Ints(ans)
	return ans
}
