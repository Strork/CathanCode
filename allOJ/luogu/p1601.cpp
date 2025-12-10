#include <bits/stdc++.h>
using namespace std;
int la, lb, n;
int a[1005], b[1005], c[1005];

void add() {
    la = 1, lb = 1;
    a[1] = 1; b[1] = 2;
    // 执行 n - 2 次高精度加法
    for (int i = 1; i <= la; ++i) {
        c[i] = a[i] + b[i];
        if (c[i] >= 10) {
            c[i] -= 10;
            c[i + 1]++;
        }
    }
    if (a[la + 1]) la++;
    for (int i = la; i >= 1; --i) cout << a[i];
}

int main() {
    cin >> n;
    add();
    return 0;
}