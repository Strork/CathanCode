#include <bits/stdc++.h>
using namespace std;
string st, ed;
unordered_map<string, int> a;
queue<string> q;

int trans(int x, int dir) {
    if (dir == 0)
        return x - 3 > 0 ? x - 3 : 0;
    else if (dir == 1)
        return x + 3 <= 9 ? x + 3 : 0;
    else if (dir == 2)
        return (x % 3 != 1) ? x - 1 : 0;
    else if (dir == 3)
        return (x % 3 != 0) ? x + 1 : 0;
}

void bfs() {
    while (!q.empty()) {
        string x = q.front();
        // cout << x << endl;
        q.pop();
        int id = x.find('.') + 1;
        for (int i = 0; i < 4; ++i) {
            int sid;
            string tmp = x;
            if (sid = trans(id, i)) swap(tmp[id - 1], tmp[sid - 1]);
            if (a.count(tmp)) continue;
            a[tmp] = a[x] + 1;
            if (tmp == ed) return;
            q.push(tmp);
        }
    }
}

int main() {
    cin >> st >> ed;
    a[st] = 0;
    q.push(st);
    bfs();
    if (a.count(ed))
        cout << a[ed] << endl;
    else
        cout << -1 << endl;
    return 0;
}