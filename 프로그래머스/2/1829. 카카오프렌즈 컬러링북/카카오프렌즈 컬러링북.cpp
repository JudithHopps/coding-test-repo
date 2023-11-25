#include <vector>
// #include <algorithm>
#include <cstring>
using namespace std;
int visited[104][104];
int mx,cnt;
const int dy[] = { 0,0,1,-1};
const int dx[] = {1,-1,0,0};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요

int dfs(int y,int x,int m,int n,vector<vector<int>> a){
    visited[y][x] = 1;
    int cnt =1;
    
    for(int i=0;i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0||nx<0||ny>=m||nx>=n) continue;
        if(visited[ny][nx] || a[ny][nx] != a[y][x]) continue;
        cnt += dfs(ny,nx,m,n,a);
    }

  return cnt;  
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> ret;
    mx = 0, cnt = 0;
    memset(visited,0,sizeof(visited));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && picture[i][j]){
                cnt++;
                mx = max(mx,dfs(i,j,m,n,picture));
            }
        }
    }
    
    ret.push_back(cnt);
    ret.push_back(mx);
    
    return ret;
}