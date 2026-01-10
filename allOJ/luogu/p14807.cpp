#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
bool weak[N];        // 标记某个人忙
bool vis[N];         // 标记某个人入会
vector<int> a[N];    // 建图
vector<int> ans[N];  // 记录答案：这个人拉了谁
int n, m, k;
int sum = 0;

inline int read() {
    int read_num = 0, posibal = 1;
    char chh = 0;
    while (!isdigit(chh)) {
        if (chh == '-') posibal = -1;
        chh = getchar();
    }
    while (isdigit(chh)) {
        read_num = read_num * 10 + (chh - '0');
        chh = getchar();
    }
    return read_num * posibal;
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    sum++;
    vis[s] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        bool f = 0;
        for (auto y : a[x]) {
            if (!vis[y]) {
                f = 1;
                sum++;                    // 统计入会人数
                vis[y] = 1;               // 标记 y 入会
                if (!weak[y]) q.push(y);  // 只有不忙的才叫其他人
                ans[x].push_back(y);      // 记录 x 拉了 y
            }
        }
        if (f) a[0].push_back(x);  // 拉人的过程实际上就是队列的过程
    }
    if (sum < n) {
        puts("No");
        return;
    }
    puts("Yes");
    cout << a[0].size() << endl;
    for (auto x : a[0]) {
        printf("%d %d ", x, ans[x].size());
        for (auto y : ans[x]) {
            printf("%d ", y);
        }
        putchar('\n');
    }
}

int main() {
    n = read(), m = read(), k = read();
    for (int i = 1; i <= k; ++i) {
        int x = read();
        weak[x] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read();
        a[x].push_back(y), a[y].push_back(x);  // 双向图
    }
    bool ent = 0;
    for (int i = 1; i <= n; ++i)
        if (!weak[i]) {
            ent = 1;
            bfs(i);  // 从随机一个不忙的人开始
            break;
        }
    if (!ent) puts("No");
    return 0;
}