#include<bits/stdc++.h>
using namespace std;
string s;
string ans;

int main() {
    cin >> s;
    for (auto i : s) {
        if (i >= 'A' && i <= 'Z') {
            ans.push_back('_');
            ans.push_back(i-'A'+'a');
        }
        else ans.push_back(i);
    }
    cout << ans.substr(1) << endl;
    return 0;
}