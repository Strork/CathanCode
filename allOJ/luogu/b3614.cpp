#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        stack<ull> p;
        for (int i = 1; i <= n; ++i) {
            string s;
            cin >> s;
            if (s[0] == 'p') {
                if (s.size() == 4) {
                    ull x;
                    cin >> x;
                    p.push(x);
                }
                else {
                    if (p.empty()) cout << "Empty\n";
                    else p.pop();
                }
            } else if (s[0] == 's') {
                cout << p.size() << '\n';
            } else {
                if (p.empty()) cout << "Anguei!\n";
                else cout << p.top() << endl;
            }
        }
    }
    return 0;
}