#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    bool flag = 0;
    for (int num = 10000; num <= 30000; ++num) {
        int s1 = num / 100; // 前三位
        int s2 = num / 10 % 1000; // 中间三位
        int s3 = num % 1000; // 后面三个数
        if (s1%k==0 && s2%k==0 && s3%k==0) flag = 1, cout << num << endl;
    }
    if (!flag) cout << "No" << endl;
    return 0;
}