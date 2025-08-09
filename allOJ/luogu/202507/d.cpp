#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[2005], b[2005];
int pa, pb;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> a[++pa];
    }
    for (int i = k + 1; i <= n; ++i) {
        cin >> b[++pb];
    }
    int c = 1, d = 1;
    while (c <= pa || d <= pb) {
        if (c <= pa) cout << a[c++] << ' ';
        if (d <= pb) cout << b[d++] << ' ';
    }
    return 0;
}