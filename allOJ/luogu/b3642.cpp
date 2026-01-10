#include <bits/stdc++.h>
using namespace std;
struct tree {
    int l, r;
} a[1000100];
int n;

void pre(int x) {
    if (!x) return;
    cout << x << ' ';  // 根
    pre(a[x].l);       // 左
    pre(a[x].r);       // 右
}

void mid(int x) {
    if (!x) return;
    mid(a[x].l);       // 左
    cout << x << ' ';  // 根
    mid(a[x].r);       // 右
}

void net(int x) {
    if (!x) return;
    net(a[x].l);       // 左
    net(a[x].r);       // 右
    cout << x << ' ';  // 根
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].l >> a[i].r;
    pre(1);
    cout << endl;
    mid(1);
    cout << endl;
    net(1);
    cout << endl;
    return 0;
}