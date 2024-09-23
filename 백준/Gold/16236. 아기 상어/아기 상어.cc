#include <iostream>
#include <cstring>
#include <queue>
#include <set>

using namespace std;
int n, a[24][24],cnt , visited[24][24],Y,X, ret,now=2,eat;
const int dy[] = {-1,0,1,0};
const int dx[]= {0,-1,0,1};

struct A {
    int y,x,fish;
};

struct B {
    int dist, y, x;
    bool operator<(const B& other) const {
        if (dist == other.dist) {
            if (y == other.y) {
                return x > other.x;  
            }
            return y > other.y;  
        }
        return dist > other.dist;  
    }
};

priority_queue<B> pq;


/*
    가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.

    자신보다 크면 못가! 

    작은 물고기만 먹을 수 있음!!

    더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.

    아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 
    예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다
*/


void bfs(int y, int x){
    memset(visited,0,sizeof(visited));
    queue<A> q;
    visited[y][x] = 1; 
    q.push({y,x,0});

    while(q.size()){
        int y = q.front().y;
        int x = q.front().x;
        int fish = q.front().fish; 
        q.pop();

        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            // int nfish = fish;

            if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx]) continue;
            if(a[ny][nx] > now) continue;
            q.push({ny,nx,fish});
            
            
            if( a[ny][nx] > 0 && a[ny][nx] < now) {
                // nfish++;
                pq.push({visited[y][x],ny,nx});
            }

            visited[ny][nx] = visited[y][x] + 1;

        }
    }
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << visited[i][j] <<" ";
        }
        cout <<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >>n ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j]==9) {
                Y= i, X = j;
                a[i][j] = 0;
            }
            else if (a[i][j]){
                cnt++;
            }
        }
    }

    int sum = 0;
    for(int i=0;i<cnt;i++) {
        if(sum == cnt) break;
        while(pq.size()){
            pq.pop();
        }

        bfs(Y,X);

        //print();
        if(pq.empty()) break;

        auto temp = pq.top();
        //cout <<"~~~!!! "<< temp.dist << " " << temp.y <<" " << temp.x <<"\n";
        eat++;
        sum++;

        a[temp.y][temp.x] = 0;
        if(eat==now){
            now++;
            eat= 0;
        }
        ret+= visited[temp.y][temp.x] -1 ;
        Y = temp.y; X = temp.x;
    }


    cout << ret <<"\n";


    return 0;
}