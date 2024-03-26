#include<bits/stdc++.h>
using namespace std;
int n,m;
char ch[510][510];
int len = 0;
int x[300000];
int y[300000];
bool flag;

void solution(){
	flag = 1;
	for(int i = 1; i <= len; ++i){
		if(ch[x[i]+1][y[i]] == 'W') flag = 0;
		if(ch[x[i]-1][y[i]] == 'W') flag = 0;
		if(ch[x[i]][y[i]+1] == 'W') flag = 0;
		if(ch[x[i]][y[i]-1] == 'W') flag = 0;
		if(!flag) return;
	}
}

int main(){
	cin>>n>>m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			cin>>ch[i][j];
			if(ch[i][j] == 'S'){
				x[++len] = i;
				y[len] = j;
			}
		}
	solution();
	if(!flag) cout<<"No"<<endl;
	else{
		cout<<"Yes"<<endl;
		for(int i = 1; i <= len; ++i){
			if(ch[x[i]+1][y[i]] != 'S') ch[x[i]+1][y[i]] = 'D';
			if(ch[x[i]-1][y[i]] != 'S') ch[x[i]-1][y[i]] = 'D';
			if(ch[x[i]][y[i]+1] != 'S') ch[x[i]][y[i]+1] = 'D';
			if(ch[x[i]][y[i]-1] != 'S') ch[x[i]][y[i]-1] = 'D';
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				cout<<ch[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
