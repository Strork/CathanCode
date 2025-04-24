#include<bits/stdc++.h>
using namespace std;
string s;
int add;
int ans;

int main() {
    cin >> s;
    for (auto i : s) {
        if (i == 'Y') {
            if (add <= 4) ++add;
            ans += add;
        }
        else {
            add = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
