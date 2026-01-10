#include <bits/stdc++.h>
using namespace std;

list<int> l(5, 3);

int main() {
    l.push_front(6);
    l.push_back(5);
    l.unique();
    for (auto i = l.begin(); i != l.end(); i++) {
        if (*i == 3) l.insert(++i, 4);
    }
    for (auto i = l.begin(); i != l.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}