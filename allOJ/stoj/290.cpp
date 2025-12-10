#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
int n;
multimap<pii, int> a;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        a.insert({{x, y}, i});
    }
    for (auto t : a) {
        cout << t.first.first<< ' ' << t.first.second << endl;
    }
    return 0;
}