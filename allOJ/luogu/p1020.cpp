#include <bits/stdc++.h>
using namespace std;
vector<int> f, g;

int main() {
    int x;
    while (cin >> x) {
        auto it = upper_bound(f.begin(), f.end(), -x);
        if (it == f.end()) f.push_back(-x);
        else *it = -x;
        auto ite = lower_bound(g.begin(), g.end(), x);
        if (ite == g.end()) g.push_back(x);
        else *ite = x;
    }
    cout << f.size() << endl;
    cout << g.size() << endl;
    return 0;
}