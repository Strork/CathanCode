#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll f[100100] = {0, 1, 3, 5};

int main() {
    cin >> n;
    for (int i = 4; i <= n; ++i) f[i] = (f[i-1] + 2*f[i-2]) % 1000000007;
    cout << f[n] << endl;
    return 0;
}
