#include <bits/stdc++.h>
using namespace std;
const int N = 1E6;
queue<int> q;
int n;
int dis[N+5];

int main() {
    cin >> n;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x * 2 <= n && dis[2 * x] == 0) {
            q.push(x * 2);
            dis[x * 2] = dis[x] + 1;
        }
        if (x + 1 <= n && dis[x + 1] == 0) {
            q.push(x + 1);
            dis[x + 1] = dis[x] + 1;
        }
        if (x - 1 > 0 && dis[x - 1] == 0) {
            q.push(x - 1);
            dis[x - 1] = dis[x] + 1;
        }
    }
    cout << dis[n] << endl;
    return 0;
}