#include <bits/stdc++.h>
using namespace std;
string st, ed = "111110111100*110000100000";
struct Node {
    int h, g;
    string now;
    bool operator<(const Node &x) const {
        return h + g > x.g + x.h;
    }
};
int x, y;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int GetH(string s) {
    int sum = 0;
    for (int i = 0; i < 25; ++i) {
        if (s[i] != ed[i] && ed[i] != '*') ++sum;
    }
    return sum;
}

int bfs() {
    int ans = -1;
    priority_queue<Node> q;
    unordered_map<string, bool> mp;
    q.push({GetH(st), 0, st});
    mp[st] = 1;
    while (q.size()) {
        auto t = q.top();
        q.pop();
        string now = t.now;
        if (t.g > 15) continue;
        if (now == ed) return t.g;
        int x, y, id1;
        for (int i = 0; i < 25; ++i) {
            if (now[i] == '*') {
                id1 = i;
                x = i / 5 + 1;
                y = i % 5 + 1;
            }
        }
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > 5 || ny < 1 || ny > 5) continue;
            int id2 = (nx - 1) * 5 + ny - 1;
            swap(now[id1], now[id2]);
            if (!mp[now]) {
                int h = GetH(now);
                if (h + t.g + 1 > 17) continue;
                q.push(Node{GetH(now), t.g + 1, now});
                mp[now] = 1;
            }
            swap(now[id1], now[id2]);
        }
    }
    return ans;
}

int main() {
    int T; cin >> T;
    while (T--) {
        st = "";
        for (int i = 1; i <= 5; ++i) {
            string s;
            cin >> s;
            st += s;
        }
        for (int i = 0; i < 25; ++i) {
            if (st[i] == '*') {
                x = i / 5 + 1;
                y = i % 5 + 1;
            }
        }
        cout << bfs() << endl;
    }
    return 0;
}