#include<bits/stdc++.h>
using namespace std;
struct contest {
    int st, ed;
}csp[1000006]; // 由于要存一个比赛的开始以及结尾，使用结构体排序
int n;

bool mycmp(contest a, contest b) { return a.ed < b.ed; } // 按结束时间从早到晚排序
// 思考，为什么开始时间不重要

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> csp[i].st >> csp[i].ed;
    sort(csp + 1, csp + 1 + n, mycmp);
    int ans = 1, pre = csp[1].ed; // 按照前面的证明，第一场比赛（结束最早的比赛）
    // 对之后的影响是最小的，所以第一场比赛是一定要参加的（参加之后的比赛影响很大）
    for (int i = 2; i <= n; ++i) { // 枚举剩余的比赛，看看能不能参加
        if (csp[i].st >= pre) { // 假如这个比赛在上一场的结束时间之后，马上参加
            pre = csp[i].ed; // 由于我们是结束时间排序，所以这个比赛最优秀
            ++ans; // 也是最短的、结束最早的（对之后影响最小）比赛
        }
    }
    cout << ans << endl; // 按照这样的方式我们能参加最多的比赛，输出
    return 0;
}