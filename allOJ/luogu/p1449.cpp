#include <bits/stdc++.h>
using namespace std;
string str;
stack<int> s;

int main() {
    cin >> str;
    int num = 0;
    for (auto c : str) {
        if (c == '@') cout << s.top() << endl;
        else if (c != '.' && !isdigit(c)) {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            if (c == '+') s.push(a + b);
            if (c == '-') s.push(a - b);
            if (c == '*') s.push(a * b);
            if (c == '/') s.push(a / b);
        } 
        else if (c == '.') s.push(num), num = 0;
        else num = num * 10 + c - '0';
    }
    return 0;
}