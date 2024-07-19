func mergeAlternately(word1 string, word2 string) string {
	var ans string
	n := len(word1)
	if len(word2) > n {
		n = len(word2)
	}
	for i := 0; i < n; i++ {
		if i < len(word1) {
			ans += string(word1[i])
		}
		if i < len(word2) {
			ans += string(word2[i])
		}
	}
	return ans
}