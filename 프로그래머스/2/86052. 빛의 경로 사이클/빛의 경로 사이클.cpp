#include <string>
#include <vector>
#include <cstring> 
#include <algorithm>
using namespace std;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
vector<string> Grid;
int n,m;
bool visited[510][510][4];

int change_dir(char c, int d){
    if(c == 'L') {
        d = (d+3) % 4; 
    } else if (c=='R') {
        d = (d+1) % 4; 
    }
    return d; 
}

int go (int y, int x ,int d, int len){
    if(visited[y][x][d]) return len; 
    visited[y][x][d] = true;
    
    int nd = change_dir(Grid[y][x], d); 
    int ny = (y +dy[nd]+n)%n;
    int nx = (x + dx[nd]+m)%m;
    return go(ny,nx,nd,len+1);
    
}
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    Grid = grid;
    n = grid.size(); 
    m = grid[0].size(); 
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int d=0;d<4;d++){
                if(visited[i][j][d]) continue;
                int ret = go(i,j,d,0);
                answer.push_back(ret);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}