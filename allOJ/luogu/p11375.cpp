#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll lmt = 1e12;
int n, cnt;
ll s;
string d;

int main() {
    cin >> n >> s;
    cin >> d;
    for (char c : d) {
        if (c == 'U') {
            if (cnt)
                cnt--;  // 栈中有值，向上就是回退
            else if (s != 1)
                s >>= 1;  // 位运算，右移一位，等价于除以 2
        } else {
            ll t;
            if (c == 'L')
                t = s << 1;
            else
                t = (s << 1) + 1;
            if (t > lmt)
                cnt++;  // 超过答案，计入栈中
            else
                s = t;  // 直接模拟
        }
    }
    cout << s << endl;
    return 0;
}