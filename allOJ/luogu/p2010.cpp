#include<bits/stdc++.h>
using namespace std;
string month[13] = {"", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
string date[35] = {"", "01", "02", "03", "04", "05", "06", "07", "08", "09"};
int day[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int date1, date2;
int cnt;

int main() {
    cin >> date1 >> date2;
    for (int i = 10; i <= 31; ++i) date[i] = to_string(i);
    for (int i = 1; i <= 12; ++i) {
        for (int j = 1; j <= day[i]; ++j) {
            string str = month[i] + date[j];
            string rev = str;
            reverse(rev.begin(), rev.end());
            rev += str; // 年月日 字符串
            int t = stoi(rev);
            if (t >= date1 && t <= date2) ++cnt;
        }
    }
    cout << cnt << endl;

    for (int i = 1; i <= n; ++i) {
        cin >> pay >> got;
        for (int j = T; j >= pay; --j) {
            f[j] = max(f[j], f[j - pay] + got);
        }
    }
    // f[j] 表示 这些所有作业做完了选择 能得到的最高分数   f[25]  // 25分钟能拿的最大分数
    for (int j = 1; j <= T; j++) {
        if (f[j] >= k) {
            T -= j;
            break;
        }
    }
    memset(f, 0, sizeof(f));
    // 题目实际上就有了固定的价值 ----- 1
    for (int i = 1; i <= problem; ++i) {
        for (int j = T; j >= time[i]; --j) {
            f[j] = max(f[j], f[j - time[i]] + 1);
        }
    }
    cout << f[T];
    return 0;
}