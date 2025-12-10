#include<bits/stdc++.h>
using namespace std;
int a[15];
int use[15];
int n;

void dfs(int pos) {
    if (pos > n) {
        for (int i = 1; i <= n; ++i) {
            // cout << setw(5) << a[i];
            printf("%5d", a[i]);
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!use[i]) {
            a[pos] = i;
            use[i] = 1; // 表示这个数用过了
            dfs(pos + 1);
            use[i] = 0; // 回溯时把这个数拿回来
            // a[pos] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}