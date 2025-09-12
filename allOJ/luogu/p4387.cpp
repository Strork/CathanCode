#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int n;

bool check() {
    int p = 1;
    stack<int> s;
    for (int i = 1; i <= n; ++i) {
        if (s.empty()) s.push(a[p++]);
        while (s.top() != b[i] && p <= n) s.push(a[p++]);
        if (s.top() == b[i]) s.pop();
        else return 0;
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        if (check()) puts("Yes");
        else puts("No");
    }
    return 0;
}