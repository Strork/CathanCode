#include <bits/stdc++.h>
using namespace std;
vector<int> a[1555];
int n, m;
int rd[1555], cd[1555];

void bfs() {
    int x;
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i], v = b[x][i];
        dp[y] = dp[x] + v;
        rd[y]--;
        if (rd[y] == 0) q.push(y);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
    }
    return 0;
}