#include <bits/stdc++.h>
#define M 100000007
using namespace std;
unsigned long long f[3005];
int n;

int main() {
    cin >> n;
    f[0] = f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            f[i] += f[j] * f[i - j - 1];
            f[i] %= M;
        }
    }
    cout << f[n] << endl;
    return 0;
}