#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, n;
        cin >> a >> b >> n;
        if (a + b == n || a == n || b == n || (a == b && a * 3 == n)) 
            cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}