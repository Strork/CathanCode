#include<bits/stdc++.h>
using namespace std;

struct student {
    int score;
    int math, chinese, english;
    int age;
    string name;
};
student a[50];

int main(){
    a[5].age = 18;
    a[5].name = "John";
    a[5].math = 99;
    a[5].chinese = 88;
    a[5].score = a[5].math + a[5].chinese;
    cin >> a[1].english;
	return 0;
}

