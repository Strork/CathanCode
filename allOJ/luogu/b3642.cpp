#include <bits/stdc++.h>
using namespace std;
struct tr {
    int l, r;
    int high;
}tree[1001000];
int n;

void dfs(int x, int op) {
    if (x == 0) return;
    if (op == 1) cout << x << ' ';
    dfs(tree[x].l, op);
    if (op == 2) cout << x << ' ';
    dfs(tree[x].r, op);
    if (op == 3) cout << x << ' ';
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].l >> tree[i].r;
    }
    dfs(1, 1); cout << endl;
    dfs(1, 2); cout << endl;
    dfs(1, 3);
    return 0;
}