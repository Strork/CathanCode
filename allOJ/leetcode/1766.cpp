#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f[55][55];
    int fa[100010];
    vector<int> ans;
    inline int gcd(int a, int b) {
        while (b ^= a ^= b ^= a % b);
        return a;
    }
    void pre(int n) {
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
            ans.push_back(-1);
        }
        for (int i = 1; i <= 50; ++i) {
            for (int j = i; j <= 50; ++j) {
                f[i][j] = f[j][i] = 0;
                if (gcd (i, j) == 1) {
                    f[i][j] = f[j][i] = 1;
                }
                cout << i << ' ' << j  << f[i][j]<< endl;
            }
        }
    }
    void addEdge(int x, int y) {
        if (fa[x] == x) fa[x] = y;
        else if (fa[y] == y) fa[y] = x;
        else {
            int nt = fa[x];
            fa[x] = y;
            while (fa[nt] != nt) {
                int nw = nt;
                nt = fa[nt];
                fa[nw] = x;
                x = nw;
            }
            fa[nt] = x;
        }
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        pre(n);
        for (auto i : edges) {
            if (i[0] > i[1]) addEdge(i[0], i[1]);
            else addEdge(i[1], i[0]);
        }
        for (int i = 1; i < n; ++i) {
            int t = fa[i];
            cout << t;
            while (t) {
                if (f[nums[i]][nums[t]]) {
                    ans[i] = t;
                    break;
                }
                t = fa[t];
            }
            if (ans[i] == -1) {
                if (f[nums[0]][nums[i]]) ans[i] = 0;
            }
        }
        return ans;
    }
};