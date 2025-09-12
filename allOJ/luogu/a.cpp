#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Fruit {
public: // 公有
    int price;
    void print() {
        cout << price << endl;
    }
    int get_c() { // 只读
        return c;
    }
    void set_c(int x) {
        c = x;
    }
private: // 私有
    int c;
};

class Stack {
public:
    int get_top() { 
        return top;
    }
    void push() {}
private:
    int top;
    int size;
    Stack *a;
};

class Queue {
public:
    void push() {}
};

struct student {
    ll id;
    int age;
    char score;
};

int main() {
    int aaa;
    cin >> aaa;
    Fruit banana;
    Fruit apple;
    banana.set_c(5);
    apple.set_c(3);
    cout << banana.get_c() << endl;
    cout << apple.get_c() << endl;
    return 0;
}
