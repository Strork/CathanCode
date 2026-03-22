#include <bits/stdc++.h>
using namespace std;
int n, x;
set<int> a;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int o;
        scanf("%d %d", &o, &x);
        if (o == 1) {
            auto res = a.insert(x);
            if (res.second == false) puts("Already Exist");
        } else {
            if (a.size() == 0)
                puts("Empty");
            else {
                auto it = a.lower_bound(x);
                if (it != a.begin()) {
                    auto now = it--;
                    if (abs(*it - x) <= abs(*now - x)) {
                        cout << *it << endl;
                        a.erase(it);
                    } else {
                        cout << *now << endl;
                        a.erase(now);
                    }
                }
            }
        }
    }
    return 0;
}