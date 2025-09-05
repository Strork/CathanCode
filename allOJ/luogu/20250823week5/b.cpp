#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005];
int f[1005];

void pre() {
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i <= n; ++i) {
        a[i] = 1;
        for (int j = 2; j < sqrt(i); ++j) if (i % j == 0) a[i] += j, a[i] += i / j;
        int t = sqrt(i);
        if (t * t == i) a[i] += t;
    }
}

int main() {
    cin >> n;
    pre();
    for (int i = 2; i <= n; ++i) {
        for (int j = n; j >= i; --j) {
            f[j] = max(f[j], f[j - i] + a[i]);
        }
    }
    cout << f[n] << endl;
    return 0;
}