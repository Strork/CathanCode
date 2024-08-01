package everydaygo

func maxmiumScore(cards []int, cnt int) int {
	val := [1005]int{}
	ans := 0
	minEve, minOdd := 1500, 1500
	maxEve, maxOdd := 0, 0
	for _, v := range cards {
		val[v]++
	}
	id := 0
	for i := 1000; i >= 1; i-- {
		if cnt == 0 {
			break
		}
		if val[i] == 0 {
			continue
		}
		if cnt >= val[i] {
			cnt -= val[i]
			ans += val[i] * i
			if i&1 == 1 {
				minOdd = i
			} else {
				minEve = i
			}
			id = i - 1
			continue
		}
		ans += cnt * i
		id = i
		if i&1 == 1 {
			minOdd = i
		} else {
			minEve = i
		}
		break
	}
	flag := true
	if ans&1 == 1 { //如果和是单数
		flag = false
		for i := 1; i <= id; i++ {
			if val[i] <= 0 {
				continue
			}
			if i&1 == 1 {
				maxOdd = i
			} else {
				maxEve = i
			}
		}
		t := 19999
		if maxEve != 0 && minOdd != 1500 {
			t = minOdd - maxEve
			flag = true
		}
		if maxOdd != 0 && minEve != 1500 {
			t = min(t, minEve-maxOdd)
			flag = true
		}
		if !flag {
			ans = 0
		} else {
			ans -= t
		}
	}
	return ans
}
