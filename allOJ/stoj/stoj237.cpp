#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y,sr,sc,new_color;
int p[105][105];
int m_x[4]={1,0,-1,0},m_y[4]={0,1,0,-1};
void dfs(int x,int y,int o){
	if(p[x][y]!=o){
		return;
	}
	p[x][y]=new_color;
	for(int i=0;i<4;i++){
		dfs(x+m_x[i],y+m_y[i],o);
	}
	
}
signed main(){
	cin >> x >> y;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			cin >> p[i][j];
		}
	}
	cin >> sr >> sc >> new_color;
	dfs(sr,sc,p[sr][sc]);
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			cout << p[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}