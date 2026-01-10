#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int h[100005];
struct node {
    int pre, next;
} a[100005];
int hd = 1, ed = n;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 2; i <= n; ++i) {
        if (!a[1].next && h[i] != h[1])
            a[1].next = i, a[i].pre = 1;
        else if ((h[i] - h[i - 1]) * (h[i - 1] - h[a[i - 1].pre]) < 0)
            a[i - 1].next = i, a[i].pre = i - 1;
        else
            a[a[i - 1].pre].next = i, a[i].pre = a[i - 1].pre;
    }
    // for (int i = hd; i; i = a[i].next) cout << i << ' ';
    // cout << endl;
    for (int i = 1; i <= m; ++i) {
        int mi = hd, mx = hd, micnt = 1, mxcnt = 1;
        for (int j = a[hd].next; j; j = a[j].next) {
            if (h[j] < h[mi])
                mi = j, micnt = 1;
            else if (h[j] > h[mx])
                mx = j, mxcnt = 1;
            else if (h[j] == h[mi])
                micnt++;
            else if (h[j] == h[mx])
                mxcnt++;
        }
        if (mxcnt < micnt) {
            h[mx]--;
            if (h[mx] == h[a[mx].pre] || h[mx] == h[a[mx].next]) {
                if (mx == hd)
                    hd = a[hd].next;
                else {
                    a[a[mx].pre].next = a[mx].next;
                    a[a[mx].next].pre = a[mx].pre;
                }
            }
        } else {
            h[mi]++;
            if (h[mi] == h[a[mi].pre] || h[mi] == h[a[mi].next]) {
                if (mi == hd)
                    hd = a[hd].next;
                else {
                    a[a[mi].pre].next = a[mi].next;
                    a[a[mi].next].pre = a[mi].pre;
                }
            }
        }
    }
    if (!a[hd].next) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = hd; i; i = a[i].next) cout << h[i] << ' ';
    cout << endl;
    int mx = 0, mi = 999999;
    for (int i = hd; i; i = a[i].next) {
        mx = max(mx, h[i]);
        mi = min(mi, h[i]);
    }
    cout << mx - mi << endl;
    return 0;
}