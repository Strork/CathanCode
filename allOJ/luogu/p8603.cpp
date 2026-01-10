#include <bits/stdc++.h>
using namespace std;
int l[10005], r[10005], root;
char prt[100005];

void build(int x, int fa) {
    if (x > fa && r[fa]) build(x, r[fa]);
    else if (x < fa && l[fa]) build(x, l[fa]);
    else if (x > fa) r[fa] = x;
    else l[fa] = x;
}

void dfs(int x, int id) {
    if (!x) return;
    int t = x;
    while (t) ++id, t /= 10; // 统计数字位数的空格
    ++id; // 跳过横线的空格
    dfs(r[x], id);
    cout << x << ' ';
    dfs(l[x], id);
}

int main() {
    freopen("a.in", "r", stdin);
    cin >> root;
    int x;
    while (cin >> x) {
        build(x, root);
    }
    dfs(root, 1);
    return 0;
}