#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int dragon[20005];
int man[20005];
ll ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> dragon[i];
    for (int i = 1; i <= m; ++i) cin >> man[i];
    sort(dragon + 1, dragon + 1 + n);
    sort(man + 1, man + 1 + m);  
    int p = 1, q = 1;
    while (p <= n && q <= m) {
        if (man[q] >= dragon[p]) ans += man[q], ++q, ++p;
        else ++q;
    }
    if (p <= n) puts("you died!");
    else cout << ans << endl;
    return 0;
}