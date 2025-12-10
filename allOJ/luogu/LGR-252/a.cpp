#include <bits/stdc++.h>
using namespace std;
stack<int> s; // 定义一个栈 s

int main() {
    if (s.empty()) puts("栈是空的");
    s.push(5);
    cout << s.top() << endl;
    s.push(10);
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << endl;
    return 0;
}