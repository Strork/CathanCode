#include <bits/stdc++.h>
using namespace std;
int f[46000005];
int s, n, d;

int main() {
    cin >> s >> n >> d;
    for (int i = 1; i <= d; ++i) {
        int pay, v;
        cin >> pay >> v;
        for (int j = pay; j <= s*46; ++j) {
            f[j] = max(f[j], f[j - pay] + v);
        }
    }
    while (n--) {
        s += f[s];
    }
    cout << s << endl;
    return 0;
}