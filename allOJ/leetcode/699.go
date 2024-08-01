func fallingSquares(positions [][]int) []int {
	ans := make([]int, len(positions))
	posnull := make([]int, 4*len(positions))
	pos := posnull[:0]
	maxx := positions[0][1]
	for _, v := range positions {
		x := sort.Search(len(pos), func(i int) bool { return pos[i] >= v[0] })
		y := sort.Search(len(pos), func(i int) bool { return pos[i] > v[1] })
		tmp := []int{x, y}
		pos = slices.Concat(nil, pos[:x], tmp, pos[y:])
	}
	return ans
}
