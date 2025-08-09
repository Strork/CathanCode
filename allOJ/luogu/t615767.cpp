#include <bits/stdc++.h>
using namespace std;
string s;
int p[1000100];

int main() {
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    s = ".edu.cn#" + s;
    for (int i = 1; i < s.size(); ++i) {
        int len = p[i - 1];
        while (len && s[i] != s[len]) len = p[len - 1];
        if (s[i] == s[len]) p[i] = len + 1;
        if (p[i] == 7) cout << i-7 << ' ';
    }
    return 0;
}