#define ll long long
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int ans = 0;
        cout << chargeTimes.size();
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
            int k = chargeTimes[maxPos.front()];
            int a = r-l+1;
            int b = sum[r+1]-sum[l];
            cout << r << ' ' << a << ' ' << b << ' ' << k << endl;
            while ((r-l+1) * (sum[r+1]-sum[l]) + chargeTimes[maxPos.front()] > budget && l < r) {
                ++l;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

int main() {
    Solution a;
    vector<int> bb{19,63,21,8,5,46,56,45,54,30,92,63,31,71,87,94,67,8,19,89,79,25};
    vector<int> cc{91,92,39,89,62,81,33,99,28,99,86,19,5,6,19,94,65,86,17,10,8,42};
    cout << "ans is " << a.maximumRobots(bb, cc, 85LL) << endl;
    return 0;
}