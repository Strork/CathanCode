#include <bits/stdc++.h>
using namespace std;
struct tree {
    int l, r;
    char ch;
}tree[300];
int n;
int root;

void dfs(int x) {
    cout << char(x);
    if (tree[x].l != '*') dfs(tree[x].l);
    if (tree[x].r != '*') dfs(tree[x].r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char id, x, y;
        cin >> id >> x >> y;
        tree[id].l = x, tree[id].r = y;
        if (i == 1) root = id;
    }
    dfs(root);
    return 0;
}