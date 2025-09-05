#include <bits/stdc++.h>
using namespace std;
int st, ed;


int extend(queue<int> &q, int *pa, int *pb) {
    int d = pa[q.front()]; // 这一层的层高
    while (q.size() && pa[q.front()] == d) { // 寻找这一层的节点
        int x = q.front();
        q.pop();
        // +1
        for (int i = 0; i < 4; ++i) {
            string s = to_string(x); // 转成 string
            if (s[i] == '9') s[i] = '1';
            else s[i]++;
            int y = stoi(s); // 转成 int
            if (pb[y] != -1) { // 判断答案出现
                return pb[y] + pa[x] + 1;
            } else if (pa[y] != -1) { // 重复记录
                continue;
            }
            pa[y] = pa[x] + 1;
            q.push(y);
        }
        // -1
        for (int i = 0; i < 4; ++i) {
            string s = to_string(x); // 转成 string
            if (s[i] == '1') s[i] = '9';
            else s[i]--;
            int y = stoi(s); // 转成 int
            if (pb[y] != -1) { // 判断答案出现
                return pb[y] + pa[x] + 1;
            } else if (pa[y] != -1) { // 重复记录
                continue;
            }
            pa[y] = pa[x] + 1;
            q.push(y);
        }
        // swap
        for (int i = 1; i < 4; ++i) {
            string s = to_string(x); // 转成 string
            swap(s[i], s[i - 1]);
            int y = stoi(s); // 转成 int
            if (pb[y] != -1) { // 判断答案出现
                return pb[y] + pa[x] + 1;
            } else if (pa[y] != -1) { // 重复记录
                continue;
            }
            pa[y] = pa[x] + 1;
            q.push(y);
        }
    }
    return -1;
}

int bfs() {
    if (st == ed) return 0;
    int dis_a[10005], dis_b[10005];
    memset(dis_a, -1, sizeof(dis_a)); // 标记 & 距离
    memset(dis_b, -1, sizeof(dis_b));
    queue<int> qa, qb;
    qa.push(st), qb.push(ed); // qa 从起点 bfs， qb 从终点 bfs
    dis_a[st] = 0, dis_b[ed] = 0;
    while (qa.size() && qb.size()) {
        int ans = -1;
        if (qa.size() <= qb.size()) {
            ans = extend(qa, dis_a, dis_b); // 操作队列 a
        } else ans = extend(qb, dis_b, dis_a); // 操作队列 b
        if (ans > 0) return ans;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> st >> ed;
        cout << bfs() << endl;
    }
    return 0;
}