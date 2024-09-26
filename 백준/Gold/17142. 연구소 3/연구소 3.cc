#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};

int a[54][54],n,m,ret = 987654321,cnt;
int visited[54][54],wall;

vector<pair<int,int>> v2; 

/*
    가장 처음에 모든 바이러스는 비활성 상태이고, 
    활성 상태인 바이러스는 상하좌우로 인접한 모든 빈 칸으로 동시에 복제되며, 
    1초가 걸린다. 승원이는 연구소의 바이러스 M개를 활성 상태로 변경하려고 한다.
*/
void bfs(vector<int> v){
    // cnt++;
    // cout << cnt <<":\t";
    // for(int vv : v){
    //     cout << vv <<" ";
    // }
    // cout <<"\n";
    int tt = 0;
    int paint = 0; 

    memset(visited,0,sizeof(visited)); 
    queue<pair<int,int>> q; 
    queue<pair<int,int>> temp; 

    for(int vv : v){
        visited[v2[vv].first][v2[vv].second] = 1;
        q.push({v2[vv].first,v2[vv].second});
    }
    while(true){
        tt++;
        while(q.size()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny<0||nx<0||ny>=n||nx>=n||visited[ny][nx]||a[ny][nx]==1) continue;

                visited[ny][nx] = 1;
                temp.push({ny,nx});

                if(a[ny][nx] ==0){
                    paint++;
                }

            }
        }


        if(wall > paint && temp.size()){
            swap(q,temp);
        } else {
            break;
        }
    }

    if(wall == paint) ret = min(ret,tt);

}

void dfs(int idx, vector<int> v){
    if(v.size()==m){
        bfs(v);
        return;
    }

    if(idx==v2.size()){
        return;
    }

    dfs(idx+1,v);


    v.push_back(idx);
    dfs(idx+1,v);


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j]==2){
                v2.push_back({i,j});
            } else if (a[i][j] == 0){
                wall++;
            }
        }
    }
    if(wall==0) ret = 0;

    dfs(0,{});


    cout << (ret==987654321? -1 : ret) <<"\n";
    return 0;
}