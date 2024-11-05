#include <bits/stdc++.h>
using namespace std;
int ans, step, s[200005];
int id1[200005];
int id2[200005];
int len1 = 0;
int len2 = 0;
int n = 0;
string str;

int main() {
    cin >> str;
    for (auto i : str) {
        if (i == '0') s[++n] = 0;
        else s[++n] = 1;
    }
    for (int i = 1; i <= n/2; ++i) {
        if (s[i] == 1) {
            s[i] ^= 1;
            s[i+1] ^= 1;
            ++step;
            id1[++len1] = i;
        }
    }
    for (int i = n; i > n/2; --i) {
        if (s[i] == 0) {
            s[i] ^= 1;
            s[i-1] ^= 1;
            ++step;
            id2[++len2] = i;
        }
    }
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for (int i = 1; i <= n; ++i) ++cnt[s[i]];
    ans = cnt[0] * cnt[1];
    cout << ans << endl;
    cout << step << endl;
    for (int i = 1; i <= len1; ++i) printf("%d ", id1[i]);
    for (int i = len2; i >= 1; --i) printf("%d ", id2[i]);
    return 0;
}