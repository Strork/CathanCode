#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int s = 0, q = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        if (a[i] > b[i]) s++;
        else if (a[i] < b[i]) q++;
    }
    cout << s << ' ' << q << endl;
    if (s > q) cout << "S" << endl;
    else if (s < q) cout << "Q" << endl;
    else cout << "Tie" << endl;
    return 0;
}