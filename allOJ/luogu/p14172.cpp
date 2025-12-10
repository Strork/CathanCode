#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T; while (T--) {
        int n; cin >> n; string str;
        stack<char> s; bool chance = 1; // 修改机会
        cin >> str; bool lovely = 1;
        for (int i = 0; i < n; ++i) {
            if (str[i] == '(') s.push('(');
            else {
                if (s.size()) s.pop();
                else if (chance && str[i + 1] == '(') chance = 0, ++i;
                else {
                    lovely = 0;
                    cout << "No" << endl;
                    break;
                }
            }
        }
        if (lovely) {
            if (s.empty()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}