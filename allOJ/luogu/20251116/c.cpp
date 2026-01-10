#include <bits/stdc++.h>
using namespace std;
int m, n;
bitset<1000> a[1005];
string ans = "9999999", tmp;
bool f[1005];
int total;

void dfs(int x) {
    if (x >= m + 1) {
        tmp = "";
        vector<int> tid;
        for (int i = 1; i <= n; ++i) {
            auto t = a[1001] & a[i];
            if (t.count() & 1) {
                tid.push_back(i);
                if (i < 10) tmp += "00" + to_string(i);
                else if (i < 100) tmp += "0" + to_string(i);
                else tmp += to_string(i);
            }
        }
        tmp += to_string(n + 1);
        if (tmp < ans) {
            total = 1;
            ans = tmp;
            memset(f, 0, sizeof(f));
            for (auto t : tid) f[t] = 1;
        }
        else if (tmp == ans) ++total;
        return;
    }
    dfs(x + 1);
    a[1001].set(x); // 设为 1
    dfs(x + 1);
}

void solution1() {
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        if (f[i]) puts("Yes");
        else puts("No");
    }
    cout << total << '\n';
}

int main() {
    cin >> m >> n;
    a[0].set(); // 全 1
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[0] &= a[i];
    }
    if (m <= 10) solution1();
    return 0;
}