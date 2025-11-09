#include<bits/stdc++.h>
using namespace std;
int n;

bool prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i*i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void f(int x, int l) {
    if (l == n) printf("%d\n", x); // 长度 为 n 输出 x
    int t = x * 10;
    if (prime(t+1)) f(t+1, l+1);
    if (prime(t+3)) f(t+3, l+1);
    if (prime(t+7)) f(t+7, l+1);
    if (prime(t+9)) f(t+9, l+1);
}

// 1 3 7 9
int main() {
    cin >> n;
    f(2, 1);
    f(3, 1);
    f(5, 1);
    f(7, 1);
    return 0;
}