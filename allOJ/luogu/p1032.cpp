#include <bits/stdc++.h>
#define ump unordered_map<string, int>
using namespace std;
string A, B;
string a[10], b[10];
int n = 1;

int extend(queue<string>& q, ump& da, ump& db, string *a, string *b) {
    int level = da[q.front()]; // 当前层数
    while (q.size() && level == da[q.front()]) {
        string x = q.front();
        q.pop();
        for (int i = 1; i < n; ++i) {
            int cc = x.size();
            cc -= a[i].size();
            for (int j = 0; j <= cc; ++j) {
                string sub = x.substr(j, a[i].size());
                if (sub == a[i]) {
                    string y = x;
                    y.replace(j, a[i].size(), b[i]);
                    if (db.count(y)) return db[y] + da[x] + 1;
                    if (da.count(y)) continue;
                    da[y] = da[x] + 1;
                    q.push(y);
                }
            }
        }
    }
    return 11;
}

int bfs() {
    if (A == B) return 0;
    queue<string> qa, qb; // 队列：存BFS的一层节点
    unordered_map<string, int> disa, disb; // 记录距离起始的距离
    qa.push(A), qb.push(B);
    disa[A] = disb[B]= 0; // 初始化
    int step = 0;
    while (qa.size() && qb.size()) {
        int ans = 0;
        if (qa.size() <= qb.size()) {
            ans = extend(qa, disa, disb, a, b); // 扩展a
        } else ans = extend(qb, disb, disa, b, a); // 扩展b
        if (ans <= 10) return ans;
        if (++step >= 10) return -1;
    }
    return -1;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> A >> B;
    while (cin >> a[n] >> b[n]) n++;
    int ans = bfs();
    if (ans == -1) cout << "NO ANSWER!" << endl;
    else cout << ans << endl;
    return 0;
}