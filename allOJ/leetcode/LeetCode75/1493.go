package leetcode75

func longestSubarray(nums []int) int {
	var x = [2]int{-1, -1}
	var y = [2]int{-1, -1}
	ans := 0
	ff := false
	// 1 1 0 1
	for i, v := range nums {
		if v == 0 {
			ff = true
			ans = max(ans, y[1]-x[1]+y[0]-x[0])
			x[0], y[0] = x[1], y[1]
			x[1] = i
		}
		y[1] = i
	}
	ans = max(ans, y[1]-x[1]+y[0]-x[0])
	if !ff {
		ans--
	}
	return ans
}
