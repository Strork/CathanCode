#include <bits/stdc++.h>
using namespace std;
struct stu {
    string name;
    int num, age, tot;
}a[15];

int main() {
    int n;
    cin >> n;
    int no1 = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].name >> a[i].num >> a[i].age >> a[i].tot;   
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i].tot > a[no1].tot) no1 = i;
    }
    cout << a[no1].name << endl;
    return 0;
}