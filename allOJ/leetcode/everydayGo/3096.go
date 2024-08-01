package everydaygo

func minimumLevels(possible []int) int {
	var sum [100100]int
	var n int
	var ans = -1
	for i, v := range possible {
		if v == 1 {
			sum[i] = 1
		} else {
			sum[i] = -1
		}
		n = i
	}
	for i := 1; i <= n; i++ {
		sum[i] += sum[i-1]
	}
	//fmt.Println(sum)
	for i := 0; i < n; i++ {
		if sum[i] > sum[n]-sum[i] {
			ans = i + 1
			break
		}
	}
	return ans
}
