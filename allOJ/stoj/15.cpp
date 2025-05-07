#include<iostream>
using namespace std;
char c;

int main()
{
    cin >> c;
    if (c >= 'a' && c <= 'z') cout << "lower";
    else if (c >= 'A' && c <= 'Z') cout << "upper";
    return 0;
}
