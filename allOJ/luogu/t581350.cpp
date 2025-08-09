#include <bits/stdc++.h>
using namespace std;
int n, m, T;
string a, b;

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cin >> a >> b;
        int ai = 0, aj = n - 1;
        int bi = 0, bj = m - 1;
        while (a[ai] == b[bi] && ai < n) ++ai, ++bi;
        while (a[aj] == b[bj] && aj >= ai) --aj, --bj;
        if (ai == aj + 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}