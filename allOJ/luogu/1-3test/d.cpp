#include <bits/stdc++.h>
using namespace std;
struct student {
    string name;
    int y, m, d;
    int id;
}a[1005];
student b[10005];
int n;

bool mycmp(student a1, student a2) {
    if (a1.y < a2.y) return 1; // a1.y >= a2.y
    else if (a1.y == a2.y && a1.m < a2.m) return 1; // a1.y > a2.y
    else if (a1.y == a2.y && a1.m == a2.m && a1.d < a2.d) return 1;
    else if (a1.y == a2.y && a1.m == a2.m && a1.d == a2.d) {
        return a1.id > a2.id;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].name >> a[i].y >> a[i].m >> a[i].d;
        a[i].id = i;
    }
    return 0;
}