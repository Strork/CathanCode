#include <bits/stdc++.h>
using namespace std;
short f[10010][10010];
int ans, p;

short game(int x, int y) {
    if (f[x][y] == -1) return -1; 
    if (f[x][y]) return f[x][y];
    f[x][y] = -1;
    if (x == 0) return 1;
    if (y == 0) return 2;
    int num = (x + y) % p;
    return f[x][y] = game(num, (num + y) % p);
}

int main() {
    int T;
    cin >> T >> p;
    while (T--) {
        int x, y;
        cin >> x >> y;
        ans = game(x, y);
        if (ans == -1) cout << "error" << endl;
        else cout << ans << endl;
    }
    return 0;
}