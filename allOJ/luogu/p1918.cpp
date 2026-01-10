#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    set<int> s;
    unordered_map<int, int> p;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
        p[x] = i;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        auto it = s.find(x);
        if (it != s.end()) cout << p[x] << endl;
        else cout << 0 << endl;
    }
    return 0;
}