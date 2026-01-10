#include <bits/stdc++.h>
using namespace std;
int bt[100005][2];
int n;
char color[100005];
int opt[100005];

void dfs(int x) {
    int l = bt[x][0], r = bt[x][1];
    if (opt[x]) opt[l] ^= 1, opt[r] ^= 1;
    if (l) dfs(l);
    if (r) dfs(r);
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {  // 建立二叉树
        int fa;
        cin >> fa;
        if (!bt[fa][0])
            bt[fa][0] = i;
        else
            bt[fa][1] = i;
    }
    scanf("%s", color + 1);
    // string colo;
    // cin >> colo;
    // colo = "$" + colo;
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int x;
        cin >> x;
        opt[x] ^= 1;  // 操作一次 x 节点
    }
    dfs(1);  // 把历史操作转移
    for (int i = 1; i <= n; ++i) cout << opt[i] << ' ';
    cout << endl;
    for (int i = 1; i <= n; ++i) {
        int c = color[i] - '0';
        if (opt[i])
            cout << (c ^ 1);
        else
            cout << c;
    }
    return 0;
}