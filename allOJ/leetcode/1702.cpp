#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        string ans;
        ans.reserve(100000);
        int cnt[2] = {0, 0};
        bool flag = 0;
        for (auto i : binary) {
            if (i == '0') flag = 1;
            if (flag) {
                if (i == '1') ++cnt[1];
                else ++cnt[0];
            }
            else ans += '1';
        }
        if (flag) {
            ans.append(cnt[0]-1, '1');
            ans += '0';
            ans.append(cnt[1], '1');
        }
        return ans;
    }
};