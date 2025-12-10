#include <bits/stdc++.h>
using namespace std;

class student {
    int m_age;
public:
    student() { puts("无参构造 student"); }
    student(int age) {
        m_age = age;
        puts("有参数 student");
    }
    student(const student& p) {
        m_age = p.m_age;
        puts("拷贝构造 student");
    }
    int age() { return m_age; }
    int set_age(int x) {
        if (x < 0 || x > 200) cout << "检查你输入的年龄！" << endl;
        else m_age = x;
    }
};

int main() {
    student alex;
    student jam(2);
    student tom(jam);
    return 0;
}