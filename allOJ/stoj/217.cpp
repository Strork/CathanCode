#include <bits/stdc++.h>
using namespace std;
int n, m;
bool flag[1005];

int main() {
    cin >> n >> m;
    int cnt = 0;
    int del = 0;
    int i = 1;
    while (del < n) {
        if (!flag[i]) ++cnt;
        if (cnt == m) {
            flag[i] = 1;
            cout << i << ' ';
            ++del;
            cnt = 0;
        }
        ++i;
        if (i == n+1) i = 1;
    }
    return 0;
}