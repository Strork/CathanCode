#include <bits/stdc++.h>
using namespace std;
int s[1000005], siz = 0;

bool solution() {
    // stack<int> s;
    string str;
    cin >> str;
    // for (auto ch : str)
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            // s.push(str[i]);
            s[++siz] = str[i];
        } else {
            // if (s.empty()) return false;
            if (siz == 0) return false;
            char ch = str[i];
            // if (ch - 1 == s.top() || ch - 2 == s.top())
            if (ch - 1 == s[siz] || ch - 2 == s[siz])
                // s.pop();
                siz--;
            else
                return false;
        }
    }
    // if (s.size()) return false;
    if (siz) return false;
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        if (solution())
            cout << "YES" << endl;
        else
            puts("NO");
    }
    return 0;
}