#include <bits/stdc++.h>
using namespace std;
short f[10010][10010];
int ans;
int p;

short game(int x, int y, int round) {
    if (f[x][y] > 0) return f[x][y]; // 返回已知情况
    if (f[x][y] == -1) return 3; // 第二次访问，说明有循环，返回3
    if (x == 0) return 1;
    else if (y == 0) return 2;
    if (!f[x][y]) f[x][y] = -1; // flag 标记
    if (round == 1) f[x][y] = game((x + y) % p, y, round^1);
    else f[x][y] = game(x, (x + y) % p, round^1);
    return f[x][y];
}

int main() {
    int T;
    cin >> T >> p;
    while (T--) {
        int x, y;
        cin >> x >> y;
        ans = game(x, y, 1);
        if (ans == 3) cout << "error" << endl;
        else cout << ans << endl;
    }
    return 0;
}