func checkRecord(n int) int {
	const Mod = 1000000007
	f := make([][3][2]int, n)
	f[1][0][0] = 1
	f[1][1][0] = 1
	f[1][0][1] = 1
	for i := 2; i <= n; i++ {
		for j := 0; j <= 2; j++ { ///此次出勤正常
			f[i][0][0] += f[i-1][j][0]
			f[i][0][0] %= Mod
			f[i][0][1] += f[i-1][j][1]
			f[i][0][1] %= Mod
		}
		f[i][1][0] += f[i-1][0][0]
		f[i][1][0] %= Mod
		f[i][2][0] += f[i-1][1][0]
		f[i][2][0] %= Mod
		//上方为迟到
		for j := 0; j <= 2; j++ {
			f[i][0][1] += f[i-1][j][0]
			f[i][0][1] %= Mod
		} //缺席
	}
	ans := 0
	for i := 0; i <= 2; i++ {
		ans += f[n][i][0]
		ans %= Mod
		ans += f[n][i][1]
		ans %= Mod
	}
	return ans
}