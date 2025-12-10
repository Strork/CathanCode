#include <bits/stdc++.h>
using namespace std;

void del(string a, string b) {
    string ans = "";
    if (a.size() < b.size() || (a.size() == b.size() && a < b)) {
        ans += '-'; // 判断是不是 小 减去 大
    }
    if (ans == "-") swap(a, b); // 交换一下，大 减 小更方便
    // 把字符串存到数组
    // ......
    for (int i = 1; i <= la; ++i) { // 既然交换了，a 一定大
        a[i] -= b[i];
        if (a[i] < 0) { // 需要借位
            // ......
        }
    }
}

int main() {
    
    return 0;
}