#include <bits/stdc++.h>
using namespace std;
int n, m;
bool a[210][210];
int s0[210][210];
int s1[210][210];

bool numEqual(int x, int y, int z, int r) {
    int sum0 = s0[z][r] - s0[x-1][r] - s0[z][y-1] + s0[x-1][y-1];
    int sum1 = s1[z][r] - s1[x-1][r] - s1[z][y-1] + s1[x-1][y-1];
    return sum0 == sum1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char ch = getchar();
            if (ch != '0' && ch != '1') ch = getchar();
            if (ch == '0') {
                a[i][j] = 0;
                s0[i][j] = s0[i-1][j] + s0[i][j-1] - s0[i-1][j-1] + 1;
                s1[i][j] = s1[i-1][j] + s1[i][j-1] - s1[i-1][j-1];
            }
            else if (ch == '1') {
                a[i][j] = 1;
                s0[i][j] = s0[i-1][j] + s0[i][j-1] - s0[i-1][j-1];
                s1[i][j] = s1[i-1][j] + s1[i][j-1] - s1[i-1][j-1] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i + 2 - 1 <= n; ++i) {
        for (int j = 1; j + 2 - 1 <= m; ++j) {
            if (numEqual(i, j, i+2-1, j+2-1)) ++ans;
        }
    }
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")