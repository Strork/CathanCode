func waysToReachStair(k int) int {
	c := [33][33]int{}
	for i := 1; i <= 32; i++ {
		c[i][i] = 1
		c[i][0] = 1
		c[i][1] = i
	}
	for i := 3; i <= 32; i++ {
		for j := 2; j < i; j++ {
			c[i][j] = c[i-1][j] + c[i-1][j-1]
		}
	}
	ans := 0
	if k == 0 || k == 1 {
		ans++
	}
	for i := 1; i <= 31; i++ {
		downStep := (1 << i) - k //需要向下downStep次来到达k层
		if downStep < 0 {
			continue
		}
		if downStep <= i+1 { //插空法，i+1个空能否插入
			ans += c[i+1][downStep]
		} else {
			break
		}
	}
	return ans
}