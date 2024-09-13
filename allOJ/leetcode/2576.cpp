class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int ans = 0;
        sort(nums.rbegin(), nums.rend());
        queue<int> a;
        int n = nums.size() / 2;
        for (int i = 0; i < n; ++i) {
            a.push(nums[i]);
        }
        for (int i = n + 1; i < nums.size(); ++i) {
            if (nums[i] * 2 <= a.front()) {
                a.pop();
                ans += 2;
            }
        }
        return ans;
    }
};

// 8 9 10 11 12 100 x x
