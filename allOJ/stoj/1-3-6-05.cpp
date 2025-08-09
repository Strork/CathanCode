#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    cin >> s;
    string rs = s;
    reverse(rs.begin(), rs.end());
    if (rs == s) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}