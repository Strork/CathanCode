#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int f[5005];

int getf(int x) {
    if (f[x] == x) return x;
    return f[x] = getf(f[x]);
}

int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        f[getf(a)] = getf(b);
    }
    for (int i = 1; i <= p; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (getf(a) == getf(b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}