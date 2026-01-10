#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
int a[10005];

int myhash(string s) {
    int sum = 0;
    int seed = 233;
    for (int i = 0; i < s.size(); ++i) {
        sum = ((ll)sum * seed + s[i]) % mod;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        a[i] = myhash(s);
    }
    sort(a + 1, a + 1 + n);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != a[i + 1]) ++cnt;
    }
    cout << cnt << endl;
    return 0;
}