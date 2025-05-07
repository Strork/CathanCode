#include<bits/stdc++.h>
using namespace std;
string a, b;

int main() {
    cin >> a >> b;
    bool ans = true;
    auto j = b.begin();
    for (auto i : a) {
        if (i != *j) {
            ans = false;
            break;
        }
        ++j;
        if (j == b.end()) j = b.begin();
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl; 
    return 0;
}
