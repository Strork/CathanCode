package everydaygo

func getSmallestString(s string, k int) string {
	t := []byte(s)
	for i, v := range s {
		dis := int(min(v-'a', 'z'-v+1))
		if k >= dis {
			k -= dis
			t[i] = 'a'
		} else {
			t[i] -= byte(k)
			break
		}
	}
	return string(t)
}
