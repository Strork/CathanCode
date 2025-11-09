#include <bits/stdc++.h>
using namespace std;

struct student {
    int id;
    double score;
}a[105];
int n, k;

bool mycmp(student x, student y) {
    return x.score > y.score;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].id >> a[i].score;
    }
    student *p = a;
    sort(a + 1, a + 1 + n, mycmp); 
    printf("%d %g", (p+k)->id, (p+k)->score);
    return 0;
}