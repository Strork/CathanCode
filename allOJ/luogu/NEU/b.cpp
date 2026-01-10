#include <bits/stdc++.h>
using namespace std;
string a, b;

int main() {
    cin >> a >> b;
    bool flag = 1;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            if (a[i] == 'I' && b[i] == 'l') continue;
            if (b[i] == 'I' && a[i] == 'l') continue;
            flag = 0;
            break;
        }
    }
    if (!flag)
        puts("NO");
    else
        puts("YES");
    return 0;
}