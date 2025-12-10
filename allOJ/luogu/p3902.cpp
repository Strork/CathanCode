#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;

int main() {
    cin >> n;
    int x;
    cin >> x;
    a.push_back(x);
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        if (x > a.back()) a.push_back(x);
        else {
            auto it = lower_bound(a.begin(), a.end(), x);
            *it = x;
        }
    }
    cout << n - a.size() << endl;
    return 0;
}