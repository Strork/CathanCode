#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (isalnum(s[i])) ++ans;
    }
    cout << ans << endl;
    return 0;
}