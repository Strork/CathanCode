#include <bits/stdc++.h>
using namespace std;
int n;
int a[70];
int m;
bool f[70];
bool find_ans;

void dfs(int l, int s, int sum) { // 目标，起点，目前长度
    if (a[s] > l) return; // 起步就比目标长，out
    
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        m += a[i];
    }
    sort(a+1, a+1+n, greater<int>());
    for (int i = 1; i <= m; ++i) {
        dfs(i, 1, 0);
        if() {
            cout << i << endl;
            break;
        }
    }
    return 0;
}