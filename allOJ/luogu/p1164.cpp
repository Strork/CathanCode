#include <bits/stdc++.h>
using namespace std;
int money, n;
int a[105];
int f[10005];

int main() {
    cin >> n >> money;
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        for (int j = money; j >= v; --j) {
            f[j] += f[j - v];
        }
    }
    cout << f[money] << endl;
    return 0;
}