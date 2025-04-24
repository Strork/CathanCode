#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;

int main() {
    cin >> n >> m;
    ll t = 1LL;
    for (int i = 1; i <= n; ++i) {
        t = t * i % m;
    }
    cout << t << endl;
    return 0;
}
