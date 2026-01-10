#include <bits/stdc++.h>
using namespace std;

class Instrument {
   public:
    void play() { cout << "乐器在演奏声音" << endl; }
    virtual ~Instrument() {}
};
class Piano : public Instrument {
   public:
    void play() override { cout << "钢琴：叮咚叮咚" << endl; }
};
class Guitar : public Instrument {
   public:
    void play() override { cout << "吉他：咚咚当当" << endl; }
};
int main() {
    Instrument* instruments[2];
    instruments[0] = new Piano();
    instruments[1] = new Guitar();
    for (int i = 0; i < 2; ++i) {
        instruments[i]->play();
    }
    for (int i = 0; i < 3; ++i) {
        delete instruments[i];
    }
    return 0;
}