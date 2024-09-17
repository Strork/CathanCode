func lengthOfLIS(nums []int) int {
	g := make([]int, len(nums))
	g[0] = nums[0]
	pos = 0
	for i := 1; i < len(nums); i++ {
		if nums[i] > g[pos] {
			g[pos+1] = nums[i]
			pos++
		} else {
			t := sort.Search(pos+1, func(x int) bool { return nums[x] > nums[i] })
			fmt.Println(t)
		}
	}
	return 0

	/*f := make([]int, len(nums))
	  for i := 0; i < len(nums; i++ {
	      f[i] = 1;
	      for j := 0; j < i; j++ {
	          if a[i] > a[j] && f[j]+1 > f[i] {
	              f[i] = f[j] + 1;
	          }
	      }
	  }*/
}