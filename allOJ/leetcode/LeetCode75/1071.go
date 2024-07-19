func gcdOfStrings(str1 string, str2 string) string {
	len1, len2 := len(str1), len(str2)
	var suf, ans string
	for i := min(len1, len2); i >= 1; i-- {
		if len1%i != 0 || len2%i != 0 {
			continue
		}
		suf = str1[:i]
		//fmt.Println(i, suf)
		var st = strings.Repeat(suf, len1/i)
		if !strings.EqualFold(st, str1) {
			continue
		}
		st = strings.Repeat(suf, len2/i)
		if !strings.EqualFold(st, str2) {
			continue
		}
		ans = suf
		break
	}
	return ans
}