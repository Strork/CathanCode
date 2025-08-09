#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    // char name[10];
    int chn, math, eng;
    int total;
}a[1005];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].name >> a[i].chn >> a[i].math >> a[i].eng;
        a[i].total = a[i].chn + a[i].eng + a[i].math;
    }
    // a = i++;
    // a = i; i += 1;
    for (int i = 1; i <= n-1; ++i) { // 1 ~ n-1
        for (int j = i+1; j <= n; ++j) {
            bool flag = 1; // 表示是否是旗鼓相当的对手
            if (abs(a[i].eng - a[j].eng) > 5) flag = 0; // 不满足条件，记录一下
            if (abs(a[i].chn - a[j].chn) > 5) flag = 0;
            if (abs(a[i].math - a[j].math) > 5) flag = 0;
            if (abs(a[i].total - a[j].total) > 10) flag = 0;
            if (flag) cout << a[i].name << ' ' << a[j].name << endl;
            // if (flag) printf("%s %s\n", a[i].name, a[j].name);
        }
    }
    return 0;
}