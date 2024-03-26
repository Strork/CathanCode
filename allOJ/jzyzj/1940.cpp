#include<bits/stdc++.h>
using namespace std;
int n;
char a[30100];
int head,tail;
char b[30100];

int main(){
	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);
	scanf("%d",&n);
	head = 1;
	tail = n;
	for(int i = 1; i <= n; ++i) cin>>a[i];
	for(int i = 1; i <= n; ++i){
		if(a[head] < a[tail]) b[i] = a[head++];
		else b[i] = a[tail--];
	}
	int t = 0;
	for(int i = 1; i <= n; ++i){
		printf("%c",b[i]);
		++t;
		if(t == 80){
			putchar('\n');
			t = 0;
		}
	}
	return 0;
}
