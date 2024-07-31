func minRectanglesToCoverPoints(points [][]int, w int) int {
	sort.Slice(points, func(i, j int) bool {
		return points[i][0] < points[j][0]
	})
	x := points[0][0]
	ans := 1
	for i, _ := range points {
		if points[i][0]-w > x {
			x = points[i][0]
			ans++
		}
	}
	return ans
}