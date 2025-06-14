#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct node {
    int d;// 格子类型
    int tx, ty;// 传送目标坐标
    int step;// 步数
    bool visited;// 是否访问过
};
struct tt2{
	int x;
	int y;
};
node dic[500][500];
node num[26]; // 记录字母是否出现过

int main() {
	//freopen("p1825_6.in", "r", stdin);
    int a, b, sx, sy, ex, ey;
    char n;
    
    cin >> a >> b;
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            cin >> n;
            if(n == '.') {
                dic[i][j].d = 1;
            } else if(n == '#') {
                dic[i][j].d = 2;
            } else if(n == '@') {
            	dic[i][j].d = 1;
                sx = i; sy = j;
                dic[i][j].d = 1;
            } else if(n == '=') {
                ex = i; ey = j;
                dic[i][j].d = 9;
            } else{
                if(num[n-'A'].d==0){
					num[n-'A'].d = 3;
					dic[i][j].d = 3;
					num[n-'A'].tx=i;
					num[n-'A'].ty=j;
				}
				else{
					dic[i][j]=num[n-'A'];
					dic[num[n-'A'].tx][num[n-'A'].ty].d=3;
					dic[num[n-'A'].tx][num[n-'A'].ty].tx=i;
					dic[num[n-'A'].tx][num[n-'A'].ty].ty=j;
				}
            }
        }
    }
	bool breakf = 0;
	queue<tt2> q;
	tt2 m;
    m.x=sx;
    m.y=sy;
    q.push(m);
    while(!q.empty()){
		if (breakf) break;
    	tt2 m=q.front();
    	q.pop();
    	if(dic[m.x][m.y].d==1){
    		dic[m.x][m.y].d=2;
		}
    	for(int i=0;i<=3;i++){
    		int vx=dx[i]+m.x; // 下一个位置
    		int vy=dy[i]+m.y;
    		if(dic[vx][vy].d==9){
    			dic[vx][vy].step=dic[m.x][m.y].step+1;
    			cout<<dic[vx][vy].step;
				breakf = 1;
				break;
			}
    		if(dic[vx][vy].d==2){
    			continue;
			}
			if(dic[vx][vy].d==1){
				dic[vx][vy].d=2;
				tt2 k;
				k.x=vx;
				k.y=vy;
				dic[vx][vy].step=dic[m.x][m.y].step+1;
				q.push(k);
			}
			if(dic[vx][vy].d==3){
				tt2 k;
				k.x=dic[vx][vy].tx;
				k.y=dic[vx][vy].ty;
				dic[k.x][k.y].step=dic[m.x][m.y].step+1;
				dic[vx][vy].d=2;
				
				q.push(k);
			}
		}
	}
	if (!breakf) cout<<-1;
    return 0;
}