// #include <bits/stdc++.h>
// using namespace std;
// int n, w, ans = 10000;
// int a[40], car[40];

// void dfs(int cat, int car_cnt) { // x 当前猫，k 当前最大车编号
//     if (car_cnt >= ans) return; // 最优剪枝
//     if (cat >= n + 1) { // 找到一个解
//         ans = car_cnt;
//         return;
//     }

//     for (int i = 1; i <= car_cnt; ++i) { // 枚举所有的车
//         if (car[i] + a[cat] <= w) { // 这个车还能坐下来，可行性剪枝
//             car[i] += a[cat];
//             dfs(cat + 1, car_cnt);
//             car[i] -= a[cat];
//         }
//     }
//     car[car_cnt + 1] = a[cat];
//     dfs(cat + 1, car_cnt + 1); // 新的缆车
//     car[car_cnt + 1] = 0;
// }

// int main() {
//     cin >> n >> w;
//     for (int i = 1; i <= n; ++i) cin >> a[i];
//     sort(a + 1, a + 1 + n, greater<int>());
//     dfs(1, 1);
//     cout << ans << endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int n, w, ans;
int cat[20];
int car[20];

void dfs(int x, int k) {
    if (k > ans) return;
    if (x >= n + 1) {
        ans = k;
        return;
    }
    for (int i = 1; i <= k; ++i) {
        if (car[i] + cat[x] <= w) {
            car[i] += cat[x];
            dfs(x + 1, k);
            car[i] -= cat[x];
        }
    }
    car[k + 1] += cat[x];
    dfs(x + 1, k + 1);
    car[k + 1] -= cat[x];
}

int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) cin >> cat[i];
    sort(cat + 1, cat + 1 + n, greater<int>());
    ans = n;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}