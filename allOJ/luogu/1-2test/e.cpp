#include <bits/stdc++.h>
using namespace std;
int n;
int p[1000100];
int l;
bool isp[1000100];

int main() {
    cin >> n;
    memset(isp, 1, sizeof(isp));
    isp[1] = 0;
    for (int i = 2; i <= 1000000; ++i) {
        if (isp[i]) p[++l] = i;
        for (int j = 1; j <= l && i * p[j] <= 1000000; ++j) {
            isp[p[j]*i] = 0;
            if (i % p[j] == 0) break;
        }
    }
    for (int i = 1; i <= l; ++i) {
        int x = p[i];
        int y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        if (isp[y]) --n;
        if (n == 0) {
            cout << p[i] << endl;
            break;
        }
    }
    return 0;
}