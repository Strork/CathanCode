#include <bits/stdc++.h>
using namespace std;
string a, b;

void dfs(int x, int y, int l, int r) {
    if (x > y || l > r) return;
    for (int i = x; i <= y; ++i) { // 中序遍历找先序遍历的开头
        if (a[i] == b[l]) {
            dfs(x, i - 1, l + 1, l + i - x);
            dfs(i + 1, y, l + i - x + 1, r);
            cout << a[i];
        }
    }
}

int main() {
    cin >> a >> b;
    a = "^" + a;
    b = "@" + b;
    dfs(1, a.size() - 1, 1, b.size());
    return 0;
}