#include <bits/stdc++.h>
using namespace std;
int n;
char c[10];

int main() {
    cin >> n;
    int cnt = n;
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        if (c[0] >= 'A' && c[0] <= 'G' || c[0]>='R' && c[0] <= 'T') --cnt;
    }
    cout << cnt;
    return 0;
}