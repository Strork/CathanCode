package leetcode75

import "sort"

func findMinArrowShots(points [][]int) int {
	sort.Slice(points, func(i, j int) bool {
		return points[i][1] < points[j][1]
	})
	//fmt.Println(points)
	ans := 1
	y := points[0][1]
	for _, v := range points {
		if v[0] > y {
			y = v[1]
			ans++
		}
	}
	return ans
}
