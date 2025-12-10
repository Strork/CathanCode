#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005];
map<int, int> c;
int n;

inline int read() {
    int read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { if (chh=='-') posibal=-1;chh=getchar(); }
    while (isdigit(chh)) { read_num=read_num*10+(chh-'0');chh=getchar(); }
    return read_num * posibal;
}

void solution() {
    c.clear();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        a[i] += a[i - 1];
        c[a[i]]++;
    }
    c[0]++;
    int ans = 0;
    for (auto it = c.begin(); it != c.end(); ++it) it->second;
    for (auto x : c) ans = max(ans, x.second);
    cout << ans - 1 << endl;
}

int main() {
    freopen("trip.in", "r", stdin);
    freopen("trip.out", "w", stdout);
    int T = read(); while (T--) {
        solution();
    }
    return 0;
}