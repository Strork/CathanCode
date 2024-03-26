#include<bits/stdc++.h>
#define L(x) (x << 1)
#define R(x) (x << 1 | 1)
#define ll long long
//using namespace std;
using std::endl;
using std::cin;
using std::cout;

struct qaq {
	int l, r, maxx;
}tree[201000];

char buf[1<<15], *fs, *ft;
inline char getc() {return(fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;}
int read() {
	int k = 0;
	int f = 1;
	char ch = getc();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getc();
	}
	while (isdigit(ch)) {
		k = k * 10 + ch - '0';
		ch = getc();
	}
	return k * f;
}

/*void put(int x){
	if(x==0){
		putchar('0');
		putchar('\n');
		return;
	}
	if(x<0){
		putchar('-');
		x=-x;
	}
	int num=0;char ch[16];
	while(x) ch[++num]=x%10+'0',x/=10;
	while(num) putchar(ch[num--]);
	putchar('\n');
}

char buf[100000000], *ft=buf;
void printd(int x){
	static char stack[10],*s;
	if(!x)*ft++='0';
	else{
		s=stack;
		while(x)*s++=x%10+'0',x/=10;
		while(s--!=stack)*ft++=*s;
	}
}
inline void printc(char ch){
	*ft++=ch;
}*/

int main() {
	//freopen("int.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	clock_t t1 = clock();
	//std::ios::sync_with_stdio(true);
	//cin.tie(NULL);
	//cout.tie(NULL);
	//std::ofstream fout;
	//std::ifstream fin;
	//fin.open("ll.txt");
	//fout.open("b.txt");
	long long a = 1926081719260817LL;
	int b = 19260817;
	for (int i = 1; i <= 10000000; ++i) {
		
		//cin>>a;
		//cin>>b;
		//a = read();
		//b = read();
		//fin>>a;
		//fin>>b;
		
		
		//a += 1;
		//b += 1;
		//cout<<b<<'\n';
		//cout<<b<<endl;
		//cout<<b;putchar('\n');
		printf("\n");
		//fout<<b<<'\n';
		//put(b);
		//printd(b);printc('\n');
		//cout<<a<<'\n';
		//printf("%lld", a);putchar('\n');
	}
	//fwrite(buf,1,ft-buf,stdout);
	clock_t t2 = clock();
	cout<<double(t2 - t1)<<endl;
	//fout<<double(t2 - t1)<<endl;
	//fin.close();
	//fout.close();
	return 0;
}
