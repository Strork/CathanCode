class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        vector<int> recod(prizePositions.size()+1);
        int l = 0, r = 0, ans = 0;
        for (int r = 0; r < prizePositions.size(); ++r) {
            while (prizePositions[r] - prizePositions[l] > k) ++l;
            ans = max(ans, r-l+1 + recod[l]);
            recod[r+1] = max(recod[r], r-l+1);
        }
        return ans;
    }
};
