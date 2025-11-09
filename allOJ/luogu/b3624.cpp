// #include <bits/stdc++.h>
// using namespace std;
// int n, l, r;
// int w[50];
// int ans;

// void dfs(int x, int sum, int remain) {
//     if (x <= 0) return; // 搜完了
//     if (sum > r) return; // 已经超过了，不搜
//     //if (sum + remain < l) return; // 剩下的不够了，不搜
//     if (sum+w[x] >= l && sum+w[x] <= r) ++ans; // 由于方案改变，累加和
//     dfs(x-1, sum+w[x], remain-w[x]); // 选择第 x 种食物，、、、
//     dfs(x-1, sum, remain-w[x]); // 不选

// }

// int main() {
//     cin >> n >> l >> r;
//     for (int i = 1; i <= n; ++i) {
//         cin >> w[i];
//     }
//     sort(w+1, w+1+n);
//     dfs(n, 0, accumulate(w+1, w+1+n, 0));
//     cout << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n, l, r, ans;
int w[45];
int s[45];

void dfs(int x, int sum) {
    if (sum > r) return;
    if (x >= n + 1) {
        if (sum >= l) ++ans;
        return;
    }
    dfs(x + 1, sum + w[x]);
    dfs(x + 1, sum);
}

int main() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    sort(w + 1, w + 1 + n, greater<int>());
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}