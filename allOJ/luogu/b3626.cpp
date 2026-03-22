#include <bits/stdc++.h>
using namespace std;
const int N = 1E6;
queue<int> q;
int n;
int dis[N + 5];

int main() {
    cin >> n;
    q.push(1);              // 别忘了起点！
    while (!q.empty()) {    // 还有没搜完的节点的话
        int x = q.front();  // x 是当前位置
        q.pop();
        if (x * 2 <= n && dis[2 * x] == 0) {  // 如果 2x 没来过，入队并记录次数
            q.push(x * 2);
            dis[x * 2] = dis[x] + 1;
        }
        if (x + 1 <= n && dis[x + 1] == 0) {  // 如果 x+1 没来过，入队并记录次数
            q.push(x + 1);
            dis[x + 1] = dis[x] + 1;
        }
        if (x - 1 > 0 && dis[x - 1] == 0) {  // 如果 x-1 没来过，入队并记录次数
            q.push(x - 1);
            dis[x - 1] = dis[x] + 1;
        }
    }
    cout << dis[n] << endl;
    return 0;
}