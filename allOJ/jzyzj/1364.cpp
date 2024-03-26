#include<bits/stdc++.h>
using namespace std;
char s[100];
struct qaq{
	char ch;
	bool end;
	int lin[26];
}tire[600100];
int len = 0;
int n;

void add(int i,int pos){
	int val = s[i] - 'A';
	if(!tire[pos].lin[val]){
		tire[pos].lin[val] = ++len;
		tire[len].ch = val;
		tire[len].end = 0;
	}
	int nt = tire[pos].lin[val];
	if(i == n){
		tire[nt].end = 1;
		return;
	}
	add(i+1,nt);
}

int main(){
	//freopen("a.txt","r",stdin);
	while(~scanf("%s",s+1)){
		n = strlen(s+1); 
		add(1,0);
	}
	printf("%d\n",len+1);
	return 0;
}
