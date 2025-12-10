#include <bits/stdc++.h>
using namespace std;

int GetMaxD(int x) {
    if (x == 1) return 0;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return x / i;
    }
    return 1;
}

int main() {
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        vector<int> a, b;
        a.push_back(x);
        while (x = GetMaxD(x)) a.push_back(x);
        b.push_back(y);
        while (y = GetMaxD(y)) b.push_back(y);
        x = a.size() - 1, y = b.size() - 1;
        while (a[x] == b[y] && x >= 0 && y >= 0) x--, y--;
        printf("%d\n", x + y + 2);
    }
    return 0;
}