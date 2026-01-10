#include <bits/stdc++.h>
using namespace std;
string s;
int d[30000005];
int ans = 1;

int main() {
    string str;
    cin >> str;
    s += '#';
    for (auto c : str) s += c, s += '#';
    s = "%" + s + "$";
    int r = -1, m = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i <= r)
            d[i] = min(d[m * 2 - i], r - i + 1);
        else
            d[i] = 1;
        while (s[i + d[i]] == s[i - d[i]]) ++d[i];
        if (i + d[i] > r) r = i + d[i] - 1, m = i;
    }
    return 0;
}