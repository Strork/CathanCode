#include <bits/stdc++.h>
using namespace std;
int c, n;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> c >> n;
    for (int i = 1; i <= n; ++i) {
        int f[330] = {};
        memset(f, 0, sizeof(f));
        string s;
        cin >> s;
        int p = -1;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (s[j] == ',') {
                p = j;
                break;
            }
        }
        s = s.substr(p + 1);
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == 'c') j += 4, f['c'] += 1;
            else if (s[j] == 'b') j += 4, f['b'] += 1;
            else if (s[j] == 'f') j += 5, f['f'] += 1;
            else if (s[j] == 'd') j += 6, f['d'] += 1;
            else if (s[j] == 'l') j += 8, f['l'] += 1;
            else if (s[j] == 'i') j += 3, f['i'] += 1;
        }
        // cout << s << endl;
        if (f['d']) puts("double");
        else if (f['f']) puts("float");
        else if (f['l']) puts("longlong");
        else if (f['i']) puts("int");
        else if (f['c'] && f['b']) puts("int");
        else if (f['c'] > 1 || f['b'] > 1) puts("int");
        else if (f['c'] == 1) puts("char");
        else puts("bool");
    }
    return 0;
}