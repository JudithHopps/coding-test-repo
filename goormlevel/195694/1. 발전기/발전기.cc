#include <iostream>
#include <queue> 
using namespace std;
const int dy[]= {0,0,1,-1};
const int dx[]= {1,-1,0,0};

const int MAX_N = 1004; // 배열의 최대 크기
int n, a[MAX_N][MAX_N], visited[MAX_N][MAX_N], ret=0;
queue<pair<int,int>> q; 
void bfs(int y, int x) {
    visited[y][x] = 1;
	  q.push({y,x});
		
	  while(!q.empty()){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx] || !a[ny][nx]) continue;
				visited[ny][nx] = 1;
        q.push({ny,nx});
    	}
		}
}

int main() {
    cin >> n;
    if (n > MAX_N) { // n이 배열의 최대 크기를 초과하는 경우
        cerr << "Error: n is too large!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] && !visited[i][j]) {
                ret++;
                bfs(i, j);
            }
        }
    }
    
    cout << ret << "\n";
    return 0;
}
