#include <bits/stdc++.h>
using namespace std;
struct student {
    string name;
    int age;
    int total;
}a[10];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].name >> a[i].age >> a[i].total;
        a[i].age += 1;
        a[i].total *= 12;
        a[i].total /= 10;
        if (a[i].total > 600) a[i].total = 600;
        cout << a[i].name << ' ' << a[i].age << ' ' << a[i].total << endl;
    }
    return 0;
}