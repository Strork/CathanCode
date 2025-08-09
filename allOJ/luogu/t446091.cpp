#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
    int y, nt;
}e[N<<1];
int n, id;
int lin[N], ans = N;

void adde(int x, int y) {
    e[id].y = y;
    e[id].nt = lin[x];
    lin[x] = id++;
}

int dfs(int x, int father) {
    int sum = 1, res = 0;
    for (int i = lin[x]; i; i = e[i].nt) {
        int y = e[i].y;
        if (y == father) continue;
        int t = dfs(y, x);
        sum += t;
        res = max(res, t);
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main() {
    cin >> n;
    int x, y;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        adde(x, y); adde(y, x);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}