#include <bits/stdc++.h>
using namespace std;
int p[2000005];
int nt[2000005];
int pre[2000005];
string s, t;

int main() {
    cin >> s >> t;
    s = t + "$" + s;
    nt[0] = 1;
    pre[1] = 0;
    for (auto i = 1; i < s.size(); ++i) {
        int len = p[pre[i]];
        nt[i] = i+1;
        while (len != 0 && s[i] != s[len]) {
            len = p[len-1];
        }
        if (s[i] == s[len]) p[i] = len + 1;
        if (p[i] == t.size()) {
            int id = i;
            for (int j = 1; j <= t.size(); ++j) id = pre[id];
            nt[id] = i+1;
            pre[i+1] = id;
        }
        else {
            pre[i+1] = i;
        }
    }
    for (int i = nt[t.size()]; i < s.size(); i = nt[i]) {
        cout << s[i];
    }
    return 0;
}