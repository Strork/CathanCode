#include <bits/stdc++.h>
using namespace std;
int hotel[50] = {0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};
int a, b, n;
int ans[50];

int main() {
    cin >> a >> b >> n;
    for (int i = 1; i <= n; ++i) cin >> hotel[i + 13];
    sort(hotel + 1, hotel + 1 + n + 13); // 保证旅馆有序
    ans[0] = 1;
    for (int i = 1; i <= n + 13; ++i) {
        for (int j = i - 1; j >= 0; j--) {
            int dis = hotel[i] - hotel[j];
            if (dis >= a && dis <= b) {
                ans[i] += ans[j];
            }
        }
    }
    cout << ans[n + 13] << endl;
    return 0;
}