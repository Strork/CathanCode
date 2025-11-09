#include <bits/stdc++.h>
using namespace std;

int read() {
    int read_num = 0, posibal = 1; char chh = 0;
    while (!isdigit(chh)) { 
        if (chh == '-') posibal = -1;
        chh = getchar(); 
    }
    while (isdigit(chh)) { 
        read_num = read_num * 10 + (chh - '0');
        chh = getchar(); 
    }
    return read_num * posibal;
}

int main() {
    return 0;
}