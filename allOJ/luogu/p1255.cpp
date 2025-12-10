#include <bits/stdc++.h>
using namespace std;
int a[10005], b[10005], c[10005], la, lb, lc;
int n;

void sum_num() {
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= lb; ++i) {
        c[i] += a[i] + b[i];
        if (c[i] > 9) c[i + 1]++, c[i] -= 10;
    }
    if (c[lb + 1]) lc = lb + 1;
    else lc = lb;
    for (int i = 1; i <= lb; ++i) a[i] = b[i];
    la = lb;
    for (int i = 1; i <= lc; ++i) b[i] = c[i];
    lb = lc;
}

int main() {
    cin >> n;
    if (n <= 1) {
        cout << 1 << endl;
        return 0;
    }
    else if (n == 2) {
        cout << 2 << endl;
        return 0;
    }
    a[1] = b[1] = 1, la = lb = 1;
    for (int i = 2; i <= n; ++i) {
        sum_num();
    }
    for (int i = lb; i >= 1; i--) cout << b[i];
    return 0;
}