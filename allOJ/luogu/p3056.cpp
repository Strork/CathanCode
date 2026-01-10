#include <bits/stdc++.h>
using namespace std;
stack<int> s;
string a;
int ans;

int main() {
    cin >> a;
    for (auto c : a) {
        if (c == '(') s.push(1);
        else {
            if (s.size()) s.pop(); // 如果能匹配，直接出栈
            else {
                ans++;
                s.push(1);
            }
        }
    }
    cout << ans + s.size() / 2 << endl;
    return 0;
}