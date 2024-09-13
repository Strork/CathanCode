#define ll long long
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int ans = 0;
        vector<ll> sum(chargeTimes.size()+1);
        for (int i = 1; i <= runningCosts.size(); ++i) sum[i] = sum[i-1] + runningCosts[i-1];

        //NlogN做法，使用set获得区间[L, R]的最大值

        /*multiset<int> maxNum;
        maxNum.insert(0);
        for (int l=0, r=0; r < chargeTimes.size(); ++r) {
            maxNum.insert(chargeTimes[r]);
            while ((r-l+1) * (sum[r+1]-sum[l]) + *maxNum.rbegin() > budget) {
                auto it = maxNum.find(chargeTimes[l]);
                if (it != maxNum.end()) maxNum.erase(it);
                ++l;
            }
            ans = max(ans, r-l+1);
        }
        return ans;*/

        ///使用单调队列维护区间最大值，因此是O(N)

        deque<int> maxPos;
        for (int l=0, r=0; r < chargeTimes.size(); ++r) {
            //maxNum.insert(chargeTimes[r]);
            while (!maxPos.empty() && maxPos.front() < l) maxPos.pop_front();
            while (!maxPos.empty() && chargeTimes[maxPos.back()] < chargeTimes[r]) maxPos.pop_back();
            maxPos.push_back(r);
            while ((r-l+1) * (sum[r+1]-sum[l]) + chargeTimes[maxPos.front()] > budget) {
                ++l;
            }
            ans = max(ans, r-l+1);
        }
    }
};