#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> a, b;

inline ll read() {
    ll read_num = 0, posibal = 1;
    char chh = 0;
    while (!isdigit(chh)) {
        if (chh == '-') posibal = -1;
        chh = getchar();
    }
    while (isdigit(chh)) {
        read_num = read_num * 10 + (chh - '0');
        chh = getchar();
    }
    return read_num * posibal;
}

bool dfs(int x, ll t, ll sum, int cnt) {
    if (x >= n + 1) {
        return sum * 1.0 / cnt <= t;
    }
    if (dfs(x + 1, min(t, b[x]), sum + a[x], cnt + 1)) return true;
    if (dfs(x + 1, t, sum, cnt)) return true;
    return false;
}

void solution1() {
    a.clear(), b.clear();
    a.push_back(0), b.push_back(0);
    int cnt = 0;
    ll sum = 0;
    ll r = 1LL << 40;
    for (int i = 1; i <= n; ++i) {
        int x = read(), y = read();
        a.push_back(x), b.push_back(y);
        if (a[i] > b[i]) ++cnt, sum += a[i], r = min(r, b[i]);
    }
    if (cnt == 0)
        puts("YES");
    else if (dfs(1, r, sum, cnt))
        puts("YES");
    else
        puts("NO");
}

void solution() {
    cin >> n;
    if (n <= 25) solution1();
    // int cnt = 0;
    // ll sum = 0;
    // int l = 0, r = 0;
    // for (int i = 1; i <= n; ++i) {
    //     int x = read(), y = read();
    //     a.push_back(x), b.push_back(y);
    //     if (a[i] > b[i]) ++cnt, sum += a[i];
    // }
}

int main() {
    int T = read();
    while (T--) solution();
    return 0;
}