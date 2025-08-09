#include <bits/stdc++.h>
using namespace std;
struct pp {
    string name, loc;
    int pay, level;
    int id, big;
}a[150], bangzhu, fu1, fu2;

bool mycmp(pp x, pp y) {
    if (x.pay > y.pay) return true;
    else if (x.pay == y.pay) {
        return x.id < y.id;
    }
}

bool cmp2(pp x, pp y) {
    if (x.big < y.big) return true;
    else if (x.big == y.big) {
        return x.level > y.level;
    } else return x.id < y.id;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].name >> a[i].loc >> a[i].pay >> a[i].level;
        if (a[i].loc == "BangZhu") {
            bangzhu.name = a[i].name;
            bangzhu.loc = "BangZhu";
            bangzhu.level = a[i].level;
        } else if (a[i].loc == "FuBangZhu") {
            if (fu1.id == 0) {
                fu1.name = a[i].name;
                fu1.loc = "FuBangZhu";
                fu1.level = a[i].level;
            } else {
                fu2.name = a[i].name;
                fu2.loc = "FuBangZhu";
                fu2.level = a[i].level;
            }
        }
        a[i].id = i;
    }
    sort(a+1, a+1+n, mycmp);
    int now = 1;
    for (int i = 1; i <= 2 && now <= n; ++now) {
        if (a[now].loc != "BangZhu" && a[now].loc != "FuBangZhu") {
            a[now].loc = "HuFa";
            a[now].big = 1;
            ++i;
        }
    }
    for (int i = 3; i <= 6 && now <= n; ++now) {
        if (a[now].loc != "BangZhu" && a[now].loc != "FuBangZhu") {
            a[now].loc = "ZhangLao";
            a[now].big = 2;
            ++i;
        }
    }
    for (int i = 7; i <= 13 && now <= n; ++now) {
        if (a[now].loc != "BangZhu" && a[now].loc != "FuBangZhu") {
            a[now].loc = "TangZhu";
            a[now].big = 3;
            ++i;
        }
    }
    for (int i = 14; i <= 38 && now <= n; ++now) {
        if (a[now].loc != "BangZhu" && a[now].loc != "FuBangZhu") {
            a[now].loc = "JingYing";
            a[now].big = 4;
            ++i;
        }
    }
    cout << bangzhu.name << ' ' << bangzhu.loc << ' ' << bangzhu.level << endl;
    cout << fu1.name << ' ' << fu1.loc << ' ' << fu1.level << endl;
    cout << fu2.name << ' ' << fu2.loc << ' ' << fu2.level << endl;
    sort(a+1, a+1+n, cmp2);
    for (int i = 1; i <= n; ++i) {
        if (a[i].loc == "BangZhu" || a[i].loc == "FuBangZhu") continue;
        cout << a[i].name << ' ' << a[i].loc << ' ' << a[i].level << endl;
    }
    return 0;
}