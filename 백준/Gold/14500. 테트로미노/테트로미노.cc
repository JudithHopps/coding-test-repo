#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n,m,a[504][504],visited[504][504],visited2[504][504];
int ret = 0;


const int dy[]= {0,0,1,-1};
const int dx[] = {1,-1,0,0};

void dfs(int cnt ,int y,int x, int sum ){
    visited[y][x] = 1;
    if(cnt==4){
        ret = max(ret,sum);
        visited[y][x] = 0;
        return;
    }

    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m||visited[ny][nx]) continue;
        dfs(cnt+1,ny,nx,sum+a[ny][nx]);
    }
    visited[y][x] = 0;
}

void T(int y, int x) {
	int sum, dir, ny, nx;
	for (int i = 0; i < 4; i++) {
		sum = a[y][x];
		for (dir = 0; dir < 4; dir++) {
			if (dir == i)
				continue;
			ny = y + dy[dir];
			nx = x + dx[dir];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m)
				sum += a[ny][nx];
		}
		if (sum > ret)
			ret = sum;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dfs(1,i,j,a[i][j]);
            T(i,j);
        }
    }




    cout << ret <<"\n";
    
    return 0;
}