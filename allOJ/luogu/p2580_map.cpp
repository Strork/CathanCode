#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<string, int> name;
bool f[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string t;
        cin >> t;
        name[t] = i;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        string t;
        cin >> t;
        auto it = name.find(t);
        if (it != name.end()) {
            if (f[it->second]) cout << "REPEAT" << endl;
            else {
                f[it->second] = 1;
                cout << "OK" << endl;
            }
        } else cout << "WRONG" << endl;
    }
    return 0;
}