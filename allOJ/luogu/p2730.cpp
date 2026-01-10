#include <bits/stdc++.h>
using namespace std;
struct node {
    int dis;
    char opt;
};
unordered_map<string, node> dis[2];
char stc[101000], edc[101000];
string st = "12345678", ed = "";

int extend(queue<string> &q, int a, int b) {
    auto t = q.front();
    int d = dis[a][t].dis;
    while (q.size() && d == dis[a][q.front()].dis) {
        t = q.front();
        q.pop();
        // A : 交换上下两行（翻转）
        string s = t;
        reverse(s.begin(), s.end());
        if (dis[b].find(s) != dis[b].end()) {
            // ji
            return dis[];
        }
        dis[a][s].dis = dis[a][t].dis + 1;
        // 记录流程
        dis[]
        // B :
        // C :
    }
}

int bfs() {
    if (st == ed) return 0;
    dis[0][st].dis = 0, dis[1][ed].dis = 0;
    queue<string> q1, q2;
    q1.push(st), q2.push(ed);
    int ans = 0;
    while (q1.size() && q2.size()) {
        if (q1.size() <= q2.size()) {
            ans = extend(q1, 0, 1);
        } else ans = extend(q2, 1, 0);
        if (ans > 0) return ans;
    }
    return 0;
}

int main() {
    for (int i = 1; i <= 8; ++i) {
        int x; cin >> x;
        ed += '0' + x;
    }
    cout << bfs() << endl;
    return 0;
}