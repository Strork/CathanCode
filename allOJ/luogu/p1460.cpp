#include <bits/stdc++.h>
using namespace std;
int n, g;
int vtm[30];
int food[20][30];
struct qq{ // 搜索节点
    int v[30];   // 目前奶牛已经补充的营养
    int ans[30]; // 已经吃的饲料的编号
    int kd = 0;  // 目前已经用了几种饲料
    int nowFood; // 当前搜索到第几种饲料了
}csz;
qq ans;

bool check(qq a) { // check 函数验证：营养够了没有
    for (int i = 1; i <= n; ++i) {
        if (a.v[i] < vtm[i]) return false;
    }
    return true;
}

void bfs(int x) {
    queue<qq> q;
    qq st = csz;
    st.kd = 1;
    st.ans[1] = x;
    st.nowFood = x;
    for (int i = 1; i <= n; ++i) {
        st.v[i] += food[x][i];
    }
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
    ans.kd = g;
    for (int i = 1; i <= g; ++i) {
        ans.ans[i] = i;
        for (int j = 1; j <= n; ++j) {
            cin >> food[i][j];
        }
    }
    for (int i = 1; i <= g; ++i) bfs(i);
    cout << ans.kd << ' ';
    for (int i = 1; i <= ans.kd; ++i) cout << ans.ans[i] << ' ';
    return 0;
}