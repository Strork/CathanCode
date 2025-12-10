#include <bits/stdc++.h>
using namespace std;
int a[10005];
int n;

bool dfs(int x, int dep) {
    if (x == dep) return a[x] == n;
    int maxx = a[x] << (dep - x); // x == 3, dep == 5
    if (maxx < n) return false; // 按照最快的速度增长也不够
    for (int i = x; i >= 1; --i) { // 优化搜索顺序
        int t = a[x] + a[i];
        if (t > n) continue; // 可行剪枝
        a[x+1] = t;
        if (dfs(x + 1, dep)) return true;
    }
    return false;
}

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    cout << n * 2 << endl;
    // a[1] = 1;
    // int dep = 1;
    // while (!dfs(1, dep)) dep++;
    // for (int i = 1; i <= dep; ++i) cout << a[i] << ' ';
    return 0;
}