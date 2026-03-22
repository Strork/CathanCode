#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, q;

int main() {
    cin >> n >> m >> q;
    cout << n * m - min(n, q) << endl;
    return 0;
}