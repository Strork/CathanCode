#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll f[2000100] = {0, 0, 1, 1, 2, 5, 6, 12};

int main() {
    // 0 1 2 3 4 5 6 7 8 9
    // 6 2 5 5 4 5 6 3 7 6
    // 0 0 1 1 2 5 6 12
    // 2 1
    // 3 1
    // 4 1
    // 5 3
    // 6 3
    // 7 1
    cin >> n;
    for (int i = 8; i <= n; ++i)
        f[i] = (f[i-2] + f[i-3] + f[i-4] + f[i-5]*3 + f[i-6]*3 + f[i-7]) % 1000000007;
    cout << f[n] << endl;
    return 0;
}
