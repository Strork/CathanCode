#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> g;
    vector<vector<int>> id;
    vector<vector<int>> pregcd;
    vector<int> ans;
    vector<int> dep;

    inline int gcd(int a, int b) {
        while (b ^= a ^= b ^= a %= b);
        return a;
    }
    void dfs(vector<int>& nums, int x, int depth) {
        dep[x] = depth;
        int val = nums[x];
        for (auto i : pregcd[val]) {
            if (!id[i].empty()) {
                int tans = id[i].back();
                if (ans[x] == -1 || dep[tans] > dep[ans[x]]) {
                    ans[x] = tans;
                }
            }
        }

        id[val].push_back(x);
        for (auto i : g[x]) {
            if (dep[i] != -1) continue;
            dfs(nums, i, depth + 1);
        }
        id[val].pop_back();
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        g.resize(n);
        ans.resize(n, -1);
        id.resize(51);
        pregcd.resize(51);
        dep.resize(n, -1);

        for (int i = 1; i <= 50; ++i) {
            for (int j = i; j <= 50; ++j) {
                if (gcd(i, j) == 1) {
                    pregcd[i].push_back(j);
                    pregcd[j].push_back(i);
                }
            }
        }

        for (auto i : edges) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        dfs(nums, 0, 0); //x, depth
        return ans;
    }
};