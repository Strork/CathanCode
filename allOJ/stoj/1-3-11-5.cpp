#include<iostream>
using namespace std;
int month[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans[10];

int main() {
    int n;
    cin >> n;
    int dd = 1, mm = 1, yy = 1900;
    int week = 1;
    while (yy <= 1900 + n - 1) {
        if ((yy % 400 == 0) || (yy % 4 == 0 && yy % 100 != 0)) month[2] = 29;
        else month[2] = 28; // 先处理 2 月的情况

        if (dd == 13) ans[week] += 1; // 统计 13 号是星期几
        dd += 1, week += 1; // 日期上涨
        if (week == 8) week = 1; // 没有星期八，变成星期一
        if (dd > month[mm]) {
            mm += 1; // 到了下个月
            dd = 1;
        }
        if (mm > 12) {
            yy += 1; // 到了下一年
            mm = 1;
        }
    }
    for (int i = 6; i <= 7; ++i) {
        cout << ans[i] << ' ';
    }
    for (int i = 1; i <= 5; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}