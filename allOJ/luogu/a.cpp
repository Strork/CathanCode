#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
stack<int> s;
=======
<<<<<<< HEAD

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
=======
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
>>>>>>> 0208b74b82ea03551bd667d2344a479dde0ad083

int main() {
    s.push(5);

    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 92f2b8088978b352098e443d243a3b9e983d907e
>>>>>>> 0208b74b82ea03551bd667d2344a479dde0ad083
