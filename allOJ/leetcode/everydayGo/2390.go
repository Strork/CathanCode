func removeStars(s string) string {
	str := make([]byte, len(s))
	pp := 0
	for _, v := range s {
		if v != '*' {
			str[pp] = byte(v)
			pp++
		} else {
			pp--
		}
	}
	ans := string(str[:pp])
	return ans
}