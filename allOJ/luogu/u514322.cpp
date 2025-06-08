#include <bits/stdc++.h>
using namespace std;
bool f[1005];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n; ++i) {
        int x;
        scanf("%d", &x);
        f[x] = 1;
    }
    for (int i = 1; i <= 1000; ++i) {
        if (f[i]) cout << i << ' ';
    }
    return 0;
}