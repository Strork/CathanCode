#include <bits/stdc++.h>
using namespace std;
string a, b;
int ans;

int main() {
    cin >> a >> b;
    if (a.size() < b.size()) ans = -1;
    else if (a.size() > b.size()) ans = 1;
    else {
        if (a > b) ans = 1;
        else if (a < b) ans = -1;
    }
    if (ans == -1) cout << "a is smaller than b" << endl;
    else if (ans == 1) cout << "a is bigger than b" << endl;
    else cout << "a is equal to b" << endl;
    return 0;
}