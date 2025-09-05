#include <bits/stdc++.h>
using namespace std;
int n, r[105];
vector<int> a[105];
stack<int> s;

void topSort() {
    while (s.size()) {
        int x = s.top();
        s.pop();
        cout << x << ' ';
        for (auto y : a[x]) {
            --r[y];
            if (r[y] == 0) s.push(y);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int y;
        while (cin >> y) {
            if (y == 0) break;
            a[i].push_back(y);
            ++r[y]; // 计算入度
        }
    }
    for (int i = 1; i <= n; ++i) if (r[i] == 0) s.push(i);
    topSort();
    return 0;
}