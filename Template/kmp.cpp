#include<bits/stdc++.h>
using namespace std;
int n,m;
struct qaq{
	char ch[210];
};
int val[210];
qaq dream[210];
qaq thing[210];
int p[210];
int id;
int ans = 0;

void getp(char *b){
	p[1] = 0;
	int j = 0;
	int len = strlen(b+1);
	for(int i = 2; i <= len; ++i){
		while(j > 0 && b[j+1] != b[i]) j = p[j];
		if(b[j+1] == b[i]) j++;
		p[i] = j;
	}
}

int kmp(char *a, char *b){
	int sum = 0;
	int j = 0;
	int len = strlen(a+1);
	int r = strlen(b+1);
	for(int i = 1; i <= len; ++i){
		while(j > 0 && b[j+1] != a[i]) j = p[j];
		if(b[j+1] == a[i]) ++j;
		if(j == r){     //匹配成功
			sum += val[id] * (i-r+1);//进行的操作
			j = p[j];   //继续匹配
		}
	}
	return sum;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; ++i) scanf("%s",thing[i].ch+1);
	for(int i = 1; i <= m; ++i) scanf("%d",&val[i]);
	for(int i = 1; i <= n; ++i) scanf("%s",dream[i].ch+1);
	for(int i = 1; i <= m; ++i){
		id = i;
		getp(thing[i].ch);
		for(int j = 1; j <= n; ++j){
			ans += kmp(dream[j].ch, thing[i].ch);
		}
	}
	printf("%d\n",ans);
	return 0;
}

