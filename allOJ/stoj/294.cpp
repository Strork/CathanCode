#include <bits/stdc++.h>
using namespace std;
multimap<int, int> a, b;
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x & 1) a.emplace(x, i);
        else b.emplace(x, i);
    }
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        cout << it->first << ' ';
    }
    for (auto x : b) cout << x.first << ' ';
    return 0;
}