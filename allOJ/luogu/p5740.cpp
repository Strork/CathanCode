#include <bits/stdc++.h>
using namespace std;
struct student {
    int total, math, chn, eng;
    string name;
    void getTotal() {
        total = math + chn + eng;
    }
    void printStudent() {
        cout << name << ' ';
        printf("%d %d %d", chn, math, eng);
    }
};
student a[1005];

bool mycmp(student l, student r) {
    return l.total < r.total;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].name >> a[i].chn >> a[i].math >> a[i].eng;
        // a[i].total = a[i].chn + a[i].eng + a[i].math;
        a[i].getTotal();
    }
    sort(a + 1, a + 1 + n, mycmp);
    cout << a[1].name << ' ' << a[1].chn << ' ';
    cout << a[1].math << ' ' << a[1].eng << endl;
    for (int i = 2; i <= n; ++i) {
        cout << a[i].name << ' ' << a[i].chn << ' ';
        cout << a[i].math << ' ' << a[i].eng << endl;
    }
    return 0;
}