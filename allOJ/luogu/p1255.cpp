#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005][2500];
int len[5005];

int main() {
    cin >> n;
    a[1][1] = 1; len[1] = 1;
    a[2][1] = 2; len[2] = 1;
    for (int i = 3; i <= n; ++i) { // 每次循环：前面两个数相加
        for (int id = 1; id <= len[i - 1]; i++) {
            a[i][id] += a[i - 1][id] + a[i - 2][id];
            if (a[i][id] >= 10) a[i][id] -= 10, a[i][id + 1]++;
        }
        len[i] = len[i - 1];
        if (a[i][len[i] + 1] > 0) len[i]++;
    }

    return 0;
}