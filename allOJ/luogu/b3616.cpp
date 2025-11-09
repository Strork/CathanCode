#include <bits/stdc++.h>
using namespace std;
int n;
queue<int> q;

int main() {
    cin >> n;
    int opt;
    for (int i = 1; i <= n; ++i) {
        cin >> opt;
        if (opt == 1) {
            int x;
            cin >> x;
            q.push(x);
        } else if (opt == 2) {
            if (q.empty()) cout << "ERR_CANNOT_POP" << endl;
            else q.pop();
        } else if (opt == 3) {
            if (q.empty()) cout << "ERR_CANNOT_QUERY" << endl;
            else cout << q.front() << endl;
        } else cout << q.size() << endl;
    }
    return 0;
}