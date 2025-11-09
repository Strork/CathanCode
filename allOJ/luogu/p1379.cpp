#include <bits/stdc++.h>
using namespace std;
string st, ed = "123804765";
struct Node {
    int h, g;
    string now;
    bool operator<(const Node &x) const {
        return h + g > x.g + x.h;
    }
};
int x, y;
priority_queue<Node> q;
unordered_map<string, bool> mp;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int GetH(string s) {
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        if (s[i] != ed[i] && ed[i] != '0') ++sum;
    }
    return sum;
}

int bfs() {
    q.push({GetH(st), 0, st});
    mp[st] = 1;
    while (q.size()) {
        auto t = q.top();
        q.pop();
        string now = t.now;
        if (now == ed) return t.g;
        int x, y, id1;
        for (int i = 0; i < 9; ++i) {
            if (now[i] == '0') {
                id1 = i;
                x = i / 3 + 1;
                y = i % 3 + 1;
            }
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > 3 || ny < 1 || ny > 3) continue;
            int id2 = (nx - 1) * 3 + ny - 1;
            swap(now[id1], now[id2]);
            if (!mp[now]) {
                q.push(Node{GetH(now), t.g + 1, now});
                mp[now] = 1;
            }
            swap(now[id1], now[id2]);
        }
    }
}

int main() {
    cin >> st;
    for (int i = 0; i < 9; ++i) {
        if (st[i] == '0') {
            x = i / 3 + 1;
            y = i % 3 + 1;
        }
    }
    cout << bfs();
    return 0;
}