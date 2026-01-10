#include <bits/stdc++.h>
using namespace std;
struct dancer {
    bool sex;
    int skill;
} a[200005];
int n;

struct List {
    int pre, next;
} l[10000005];

int main() {
    a[a[x].pre].next = a[y].next;
    return 0;
}