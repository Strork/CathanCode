#include<bits/stdc++.h>
using namespace std;
int n;
queue<int> q;

int main() {
    cin >> n;
    for (int i = 2; i <= n; i += 2) {
        printf("%d\n", i);
        q.push(i-1);
    }
    if (n & 1) q.push(n);
    else {
        int t = q.front();
        q.pop();
        q.push(t);
    }
    while (!q.empty()) {
        printf("%d\n", q.front());
        q.pop();
        if (!q.empty()) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }
    return 0;
}
