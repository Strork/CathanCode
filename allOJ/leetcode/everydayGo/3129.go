func numberOfStableArrays(zero int, one int, limit int) int {
	var Mod int64 = 1000000007
	dp := [201][201][2]int64{}
	for i := 1; i <= limit; i++ {
		dp[i][0][0] = 1
		dp[0][i][1] = 1
	}
	for a := 1; a <= zero; a++ {
		for b := 1; b <= one; b++ {
			dp[a][b][1] = (dp[a][b-1][0]%Mod + dp[a][b-1][1]%Mod) % Mod
			dp[a][b][0] = (dp[a-1][b][1]%Mod + dp[a-1][b][0]%Mod) % Mod
			if b-limit-1 >= 0 {
				dp[a][b][1] -= dp[a][b-limit-1][0]
				dp[a][b][1] %= Mod
			}
			if a-limit-1 >= 0 {
				dp[a][b][0] -= dp[a-limit-1][b][1]
				dp[a][b][1] %= Mod
			}
		}
	}
	return int((dp[zero][one][0] + dp[zero][one][1]) % Mod)
}