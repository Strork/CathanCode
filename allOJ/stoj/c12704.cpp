#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[100005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        int sum = s[b] - s[a - 1];
        cout << s[n] - sum << endl;
    }
    return 0;
}