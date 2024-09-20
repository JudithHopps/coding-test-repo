#include <iostream>
using namespace std;
const int dy[]={0,0,-1,1};
const int dx[]={1,-1,0,0};

int n,m,x,y,k,cmd, a[24][24];
int dice[6];
/*
    0 : 바닥 1: 윗 2 : 좌 3 : 우 4: 앞 5: 뒤
    동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
*/

void rot(int cmd){
    if(cmd==1){
       int temp = dice[0];
       dice[0] = dice[3];
       dice[3] = dice[1];
       dice[1] = dice[2];
       dice[2] = temp; 
    }
    if(cmd==2){
        int temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = temp;
    }
    if(cmd==3){
        int temp = dice[0];
        dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = temp;
    }
    if(cmd==4){
        int temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> y>> x>> k;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<k;i++){
        cin >> cmd;

        int ny = y + dy[cmd-1];
        int nx = x + dx[cmd-1];
        if(ny<0||nx<0||ny>=n||nx>=m)continue;
        y=ny;x=nx;

        rot(cmd);

        if(a[y][x]){
            dice[0]= a[y][x];
            a[y][x] = 0; 
        } else {
            a[y][x] = dice[0];
        }

        cout << dice[1] <<"\n";
    }
    
    return 0;
}