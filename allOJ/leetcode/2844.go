func minimumOperations(num string) int {
	var ans = 500
	var ff = false
	var cnt = 0
	for i := len(num) - 1; i >= 0; i-- {
		if !ff {
			if num[i] == '0' {
				ff = true
				continue
			}
		} else {
			if num[i] == '0' || num[i] == '5' {
				break
			}
		}
		cnt++
	}
	ans = min(ans, cnt)

	ff = false
	cnt = 0
	for i := len(num) - 1; i >= 0; i-- {
		if !ff {
			if num[i] == '5' {
				ff = true
				continue
			}
		} else {
			if num[i] == '2' || num[i] == '7' {
				ff = false
				break
			}
		}
		cnt++
	}
	if ff {
		cnt++
	}
	ans = min(ans, cnt)
	return ans
}