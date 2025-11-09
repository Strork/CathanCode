#include <bits/stdc++.h>
using namespace std;
char a[55][55];
int r, c, n;

int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> a[i][j];
        }
    }
    return 0;
}