#include <bits/stdc++.h>
using namespace std;
int n, a[10005];

bool iddfs(int x, int dep) {
    if (x == dep) return a[x] == n;
    if (a[x] << (dep - x) < n) return false; 
    bool vis[10005] = {0};
    for (int i = x; i; --i) {
        int t = a[x] + a[i];
        if (t > n || vis[t]) continue;
        a[x + 1] = t;
        vis[t] = 1;
        if (iddfs(x + 1, dep)) return true;
    }
    return false;
}

int main() {
    a[1] = 1;
    while ((cin >> n) && n != 0) {
        int dep = 1;
        while (!iddfs(1, dep)) ++dep;
        for (int i = 1; i < dep; ++i) cout << a[i] << ' ';
        cout << a[dep] << endl;
    }
    return 0;
}