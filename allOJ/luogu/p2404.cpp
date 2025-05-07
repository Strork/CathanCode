#include <bits/stdc++.h>
using namespace std;
int a[10];
int len = 0;
int n;

void dfs(int x, int sum) {
    if (sum == n) {
        for (int i = 1; i < len; ++i) {
            cout << a[i] << '+';
        }
        cout << a[len] << endl;
        return;
    }
    for (int i = x; i < n; ++i) {
        a[++len] = i;
        if (sum+i <= n) dfs(i, sum + i);
        a[len--] = 0;
    }
}

int main() {
    cin >> n;
    dfs(1, 0);
    return 0;
}
