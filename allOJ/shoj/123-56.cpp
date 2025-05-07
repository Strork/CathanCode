#include<bits/stdc++.h>
using namespace std;
string s;

int main() {
    cin >> s;
    int ans = 0;
    auto it = s.rbegin();
    for (auto c = s.begin(); c != s.begin() + s.size()/2; ++c) {
        if (*it != *c) ++ans;
        ++it;
    }
    cout << ans << endl;
    return 0;
}
