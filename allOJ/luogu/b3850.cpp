#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int sum;

int main() {
    cin >> n;
    while (n--) {
        ll x;
        cin >> x; 
        bool flag = 1; 
        sum = 0; // 初始化 sum
        while (x) {
            int t = x % 10; // 取当前的位
            x /= 10;
            if (flag) {
                t *= 7;
                while (t > 9) {
                    int cnt = 0;
                    int a = t;
                    while (a) {
                        cnt += a % 10;
                        a /= 10;
                    }
                    t = cnt;
                }
                sum += t;
                flag = 0; // 下一位数不变换
            } else {
                flag = 1; // 下一位数要变换
                sum += t;
            }
        }
        if (sum % 8 == 0) cout << "T" << endl;
        else cout << "F" << endl;
    }
    return 0;
}