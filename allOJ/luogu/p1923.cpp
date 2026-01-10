#include <bits/stdc++.h>
using namespace std;
priority_queue<int> Q;
int n, k;
int main() {
    cin >> n >> k;
    ++k;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        if (Q.size() < k)
            Q.push(x);
        else if (x < Q.top())
            Q.pop(), Q.push(x);
    }
    cout << Q.top() << endl;
    return 0;
}