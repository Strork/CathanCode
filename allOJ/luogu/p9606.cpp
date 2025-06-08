#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int p[1000005];

int main() {
    cin >> n >> s;
    string t = s;
    reverse(s.begin(), s.end());
    s = s + "$" + t;
    for (int i = 1; i < s.size(); ++i) {
        int len = p[i-1];
        while (s[len] != s[i] && len != 0) {
            len = p[len-1];
        }
        if (s[len] == s[i]) p[i] = len + 1;
    }
    cout << n - p[s.size()-1] << endl;
    return 0;
}