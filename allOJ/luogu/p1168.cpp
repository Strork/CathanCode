#include <bits/stdc++.h>
using namespace std;
int n;
int mid_num;

int main() {
    priority_queue<int> Q;                             // 大根堆
    priority_queue<int, vector<int>, greater<int>> q;  // 小根堆
    cin >> n >> mid_num;
    printf("%d\n", mid_num);
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        if (x < mid_num)
            Q.push(x);
        else
            q.push(x);
        if ((i & 1) == 0) continue;
        while (q.size() != Q.size()) {
            if (q.size() < Q.size()) {
                q.push(mid_num);
                mid_num = Q.top();
                Q.pop();
            } else {
                Q.push(mid_num);
                mid_num = q.top();
                q.pop();
            }
        }
        cout << mid_num << endl;
    }
    return 0;
}