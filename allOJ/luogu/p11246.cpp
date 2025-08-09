#include <bits/stdc++.h>
using namespace std;
int sqr[100005];
int f[100005];
int cnt, n;

void get_sqr() {
    for (int i = 1; i*i <= n; ++i) {
        sqr[++cnt] = i*i;
    }
}

int main() {
    cin >> n;
    get_sqr();
    memset(f,  , sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= cnt; ++i) {
        for (int j = sqr[i]; j <= n; ++j) {
            f[j] = min(f[j], f[j - sqr[i]] + 1);
        }
    }
    cout << f[n] << endl;
    return 0;
}