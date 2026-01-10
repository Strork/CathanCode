// #include <bits/stdc++.h>
// using namespace std;
// struct p1803 {
//     int x, y;
// }a[1000010];


// bool mycmp(p1803 x, p1803 y) { return x.y < y.y; }

// int main() {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; ++i) {
//         scanf("%d %d", &a[i].x, &a[i].y);
//     }
//     sort(a+1, a+1+n, mycmp);
//     int ans = 0;
//     int now = 0;
//     for (int i = 1; i <= n; ++i) {
//         if (a[i].x >= now) {
//             ++ans;
//             now = a[i].y;
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n, ans = 1;

struct contest {
    int st, ed;
}a[1000005]; // 一共 10^6 比赛

bool mycmp(contest x, contest y) { return x.ed < y.ed; }// 结束时间从早到晚排序

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].st >> a[i].ed;
    sort(a + 1, a + 1 + n, mycmp);
    int pre = a[1].ed; // 记录上一场比赛的结束时间
    for (int i = 2; i <= n; ++i) {
        if (a[i].st >= pre) { // 如果能参加这一场比赛
            pre = a[i].ed; // 更新结束时间
            ++ans; // 统计数量
        }
    }
    cout << ans << endl;
    return 0;
}