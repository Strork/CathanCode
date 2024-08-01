func fallingSquares(positions [][]int) []int {
	ans := make([]int, len(positions))
	high := make([]int, len(positions))
	maxx := positions[0][1]
	for i, _ := range positions {
		high[i] = positions[i][1]
		for j := i - 1; j >= 0; j-- {
			if positions[i][0]+positions[i][1]-positions[j][0] <= 0 {
				continue
			} else if positions[j][0]+positions[j][1]-positions[i][0] <= 0 {
				continue
			}
			fmt.Println(i, j)
			high[i] = max(high[i], high[j]+positions[i][1])
		}
		if high[i] > maxx {
			maxx = high[i]
		}
		ans[i] = maxx
	}
	return ans
}
