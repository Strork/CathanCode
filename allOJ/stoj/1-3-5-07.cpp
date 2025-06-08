#include <bits/stdc++.h>
using namespace std;
char ch[10050];
int word[305];
int len_word = 0;

int main() {
    cin.getline(ch, sizeof(ch));
    int cnt = 0;
    for (int i = 0; ch[i]; ++i) {
        if (ch[i] != ' ') ++cnt;
        else {
            if (cnt) word[++len_word] = cnt;
            cnt = 0;
        }
    }
    if (cnt) word[++len_word] = cnt;
    for (int i = 1; i < len_word; ++i) cout << word[i] << ',';
    cout << word[len_word] << endl;
    return 0;
}
