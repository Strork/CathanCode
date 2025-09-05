#include <bits/stdc++.h>
using namespace std;
struct student {
    string name;
    int math, chinese, total, id;
}a[1005];

bool mycmp(student x, student y) {
    return x.total > y.total;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].name >> a[i].chinese >> a[i].math;
        a[i].total = a[i].math + a[i].chinese;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, mycmp);
    for (int i = 1; i <= n; ++i) {
        cout << a[i].name << ' ';
        printf("%d %d %d\n", a[i].chinese, a[i].math, a[i].total);
    }
    return 0;
}