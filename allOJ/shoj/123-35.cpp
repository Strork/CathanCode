#include<bits/stdc++.h>
using namespace std;
string s;
int ans;

int main() {
    cin >> s;
    for (auto i : s) {
        if (i == 'Y') ++ans;
        else {
            if (ans) --ans;
        }
    }
    cout << ans << endl;
    return 0;
}