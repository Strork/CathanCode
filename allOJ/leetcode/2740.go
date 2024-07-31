func findValueOfPartition(nums []int) int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	fmt.Println(nums)
	t := -2000000000
	ans := 2000000000
	for _, v := range nums {
		t = v - t
		if t < ans {
			ans = t
		}
		t = v
	}
	return ans
}