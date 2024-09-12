#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>

using namespace std;


// 최단 경로 탐색...!! 

struct A {
    int cnt,dir,ry,rx,by,bx;
};

struct B {
    int y,x,dist;
};

const int dy[]={0,1,0,-1};
const int dx[]={1,0,-1,0};
const int INF = 987654321;

queue<A> q; 
int n,m,RY,RX,BY,BX;
bool visited[14][14][14][14][4];
int OY,OX,ret=INF;

char a[14][14]; 

// todo: b 매개변수
B cal(int y,int x,int dir){
    B b;
    b.dist = 0;
    

    while(true){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny<0||nx<0||ny>=n||nx>=m) break;
        if(a[ny][nx] =='#') break;
        y = ny , x = nx;
        b.dist++;
        if(ny==OY && nx == OX){
            break;
        }
    }

    b.y = y; b.x=x;
    return b;
 }
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j] =='R'){
                RY = i;
                RX = j;
                a[i][j] = '.';
            }
             if(a[i][j] =='B'){
                BY = i;
                BX = j;
                a[i][j] = '.';
            }
             if(a[i][j] =='O'){
                OY =i;
                OX = j;
            }
        }
    }
    for(int i=0;i<4;i++){
        q.push({1,i,RY,RX,BY,BX}); 
    }

    while(q.size()){
        A now = q.front(); q.pop();
        visited[now.ry][now.rx][now.by][now.bx][now.dir] = true;

         if(now.cnt > 10 || now.cnt > ret) break;
        B nextRed = cal(now.ry,now.rx,now.dir);
        B nextBlue = cal(now.by,now.bx,now.dir);

        if(make_pair(nextBlue.y,nextBlue.x) == make_pair(OY,OX)) continue; 

        if(make_pair(nextRed.y,nextRed.x) == make_pair(OY,OX) ){
            ret = min(ret,now.cnt);
            break;
        }

        if(make_pair(nextBlue.y,nextBlue.x)==make_pair(nextRed.y,nextRed.x)) {
            if(nextRed.dist < nextBlue.dist){
                nextBlue.y -= dy[now.dir];
                nextBlue.x -= dx[now.dir];
            } else {
                nextRed.y -= dy[now.dir];
                nextRed.x -= dx[now.dir];
            }
        }

        for(int d=0;d<4;d++){
            if(visited[nextRed.y][nextRed.x][nextBlue.y][nextBlue.x][d]) continue;
            q.push({now.cnt+1,d,nextRed.y,nextRed.x,nextBlue.y,nextBlue.x});
        }
    }

    cout << (ret==INF ? -1 : ret) <<"\n";

    return 0;
}