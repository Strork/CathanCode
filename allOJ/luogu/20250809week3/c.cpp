#include <bits/stdc++.h>
using namespace std;
int s[2000100];
int n, m;

int main() {
    cin >> n >> m;
    int r = 0;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        ++s[a + b];
        r = max(r, a + b);
    }
    for (int i = 2; i <= 2000000; ++i) s[i] += s[i - 1];
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << s[b<<1] - s[(a<<1) - 1] << endl;
    }
    return 0;
}