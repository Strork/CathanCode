package everydaygo

func fastPower(x, y, m int) int {
	t := 1
	for ; y > 0; y >>= 1 {
		if y&1 == 1 {
			t = t * x % m
		}
		x = x * x % m
	}
	return t
}

func getGoodIndices(variables [][]int, target int) []int {
	ans := make([]int, 0, len(variables))
	for i, v := range variables {
		t := fastPower(v[0], v[1], 10)
		if fastPower(t, v[2], v[3]) == target {
			ans = append(ans, i)
		}
	}
	return ans
}
