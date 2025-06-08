#include <bits/stdc++.h>
using namespace std;
int n, g;
int vtm[30];
int food[20][30];
struct qq{
    int got[30];
    vector<int> ans_id;
    int kind;
    int nowFood;
}csz;
qq ans;

bool check(qq a) {
    for (int i = 1; i <= n; ++i) {
        if (a.v[i] < vtm[i]) return false;
    }
    return true;
}


void bfs(int x) {
    queue<qq> q;
    qq st = csz;
    st.kind = 1;
    st.ans_id.push_back(x);
    st.nowFood = x;
    for (int i = 1; i <= n; ++i) {
        st.v[i] += food[x][i];
    }
    // 0 0 0 0
    // 50 50 50 50
    // 250 350 250 350
    q.push(st);
    while (!q.empty()) {
        qq id = q.front();
        q.pop();
        id.nowFood++;
        if (id.nowFood <= g) q.push(id); // 不吃这个饲料

        if (id.kd < ans.kd && check(id)) {
            ans.kd = id.kd;
            for (int i = 1; i <= id.kd; ++i) ans.ans[i] = id.ans[i];
        }
        
        id.kd++;
        id.ans[id.kd] = id.nowFood;
        for (int i = 1; i <= n; ++i) id.v[i] += food[id.nowFood][i];
        if (id.nowFood <= g) q.push(id); // 吃了饲料
        if (id.kd < ans.kd && check(id)) {


            ans.kd = id.kd;
            for (int i = 1; i <= id.kd; ++i) ans.ans[i] = id.ans[i];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> vtm[i];
    }
    cin >> g;
    ans.kind = g;
    for (int i = 1; i <= g; ++i) {
        ans.ans_id.push_back(i);
        for (int j = 1; j <= n; ++j) {
            cin >> food[i][j];
        }
    }
    for (int i = 1; i <= g; ++i) bfs(i);
    cout << ans.kd << ' ';
    for (int i = 1; i <= ans.kd; ++i) cout << ans.ans[i] << ' ';
    return 0;
}