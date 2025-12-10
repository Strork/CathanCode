#include <bits/stdc++.h>
using namespace std;
int fa[305];
int cnt[305];
int n;

void solution() {
    memset(cnt, 0, sizeof(cnt));
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        while (x != -1) { // 向上标记法
            cnt[x]++;
            x = fa[x];
        }
    }
    for (int i = n - 1; i >= 0; i--) { // 找编号最大的员工
        if (cnt[i] == m) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) cin >> fa[i];
    fa[0] = -1;
    int q;
    cin >> q;
    while (q--) solution();
    return 0;
}