// #include <bits/stdc++.h>
// using namespace std;
// int n, m, len;
// int a[70], nt[70];
// bool use[70];

// // 1. 可行性剪枝：只找因数、第一根小木棍必须能找到解

// bool dfs(int x, int cnt, int sum) { // 搜索起点，完成的小木棍个数，目前长度
//     if (cnt * len == m) return true; // 找到解
//     if (sum == len) return dfs(1, cnt + 1, 0); // 凑好一根了
//     int id = lower_bound(a + x, a + 1 + n, len - sum, greater<int>()) - a; //
//     枚举起点 for (int i = id; i <= n; ++i) {
//         if (use[i] || sum + a[i] > len) continue;
//         use[i] = 1;
//         if (dfs(i + 1, cnt, sum + a[i])) return 1;
//         use[i] = 0;
//         if (sum == 0 || sum + a[i] == len) return 0; //
//         第一根or最后一根不能得到解 i = nt[i];
//     }
//     return 0;
// }

// int main() {
//     cin >> n;
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         m += a[i];
//     }
//     sort(a+1, a+1+n, greater<int>()); // 小木棍排序
//     nt[n] = n;
//     for (int i = n - 1; i >= 1; --i) {
//         if (a[i] == a[i + 1]) nt[i] = nt[i + 1];
//         else nt[i] = i;
//     }
//     len = a[1]; // 从最长的小木棍开始找
//     while (len <= m) {
//         if (m % len == 0) {
//             if (dfs(1, 0, 0)) {
//                 cout << len << endl;
//                 return 0;
//             }
//         }
//         ++len;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int n, a[70], len, m;
// bool use[70];
// int nt[70];

// bool dfs(int x, int cnt, int sum) { // 搜索起点，完成的小木棍个数，目前长度
//     if (cnt * len == m) return true; // 找到解
//     if (sum == len) return dfs(1, cnt + 1, 0); // 凑好一根了
//     int id = lower_bound(a + x, a + 1 + n, len - sum, greater<int>()) - a; //
//     枚举起点 for (int i = id; i <= n; ++i) {
//         if (use[i] || sum + a[i] > len) continue;
//         use[i] = 1;
//         if (dfs(i + 1, cnt, sum + a[i])) return 1;
//         use[i] = 0;
//         if (sum == 0 || sum + a[i] == len) return 0; // 第一根or
//         other不能得到解 i = nt[i];
//     }
//     return 0;
// }

// int main() {
//     cin >> n;
//     int mx = 0;
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         mx = max(a[i], mx);
//         m += a[i];
//     }
//     sort(a + 1, a + 1 + n, greater<int>()); // 排序
//     nt[n] = n;
//     for (int i = n - 1; i >= 1; --i) {
//         if (a[i] == a[i + 1]) nt[i] = nt[i + 1];
//         else nt[i] = i;
//     }
//     for (len = mx; len < m; ++len) {
//         if (m % len == 0 && dfs(1, 0, 0)) {
//             break;
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n;
int a[555], nt[555];
bool vis[555];
int tar = 0, c;

bool dfs(int cnt, int len, int x) {
    if (cnt == c) return true;
    if (len == tar) return dfs(cnt + 1, 0, 1);
    for (int i = x; i <= n; ++i) {  // 继承上次的搜索位置，并且不搜相等数
        if (!vis[i]) {
            if (len + a[i] <= tar) {                           // 可行性剪枝
                vis[i] = 1;                                    // 排除冗余
                if (dfs(cnt, len + a[i], i + 1)) return true;  // 快速退出
                vis[i] = 0;
                if (len == 0 || len + a[i] == tar) return false;
            }
            i = nt[i];
        }
    }
    return false;
}

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());  // 搜索顺序
    nt[n] = n + 1;
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] != a[i + 1])
            nt[i] = i;
        else
            nt[i] = nt[i + 1];
    }
    for (tar = 1; tar <= sum; ++tar) {  // 可行剪枝
        if (sum % tar == 0) {
            c = sum / tar;
            if (dfs(0, 0, 1)) {  // 最优化剪枝
                cout << tar << endl;
                break;
            }
        }
    }
    return 0;
}