#include <bits/stdc++.h>
using namespace std;

bool solution() {
    stack<int> s;
    string str;
    cin >> str;
    // for (auto ch : str)
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        } else {
            if (s.empty()) return false;
            char ch = str[i];
            if (ch-1 == s.top() || ch-2 == s.top()) s.pop();
            else return false;
        }
    }
    if (s.size()) return false;
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        if(solution()) cout << "YES" << endl;
        else puts("NO");
    }
    return 0;
}