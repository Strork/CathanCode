#include <bits/stdc++.h>
using namespace std;
int k, n, T;
string s;

inline char changed(char a) { return (a == 'O' ? 'M' : 'O'); }

int main() {
    cin >> T >> k;
    while (T--) {
        cin >> n >> s;
        puts("YES");
        if (k) {
            int cnt = 0;
            for (int i = s.size() - 1; i >= 0; --i) {
                if (cnt & 1) s[i] = changed(s[i]);
                if (s[i] == 'O') ++cnt;
            }
            puts(s.data());
        }
    }
    return 0;
}