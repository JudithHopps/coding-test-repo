#include <iostream>
#include <queue>

using namespace std;
const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0}; 
int mx,ret,n,k,a[1004][1004],visited[1004][1004],b[34];

queue<pair<int,int>> q; 

int bfs(int y,int x){
	int cnt = 1;
	visited[y][x] = 1;
	q.push({y,x}); 
	int m = a[y][x]; 
	
	while(q.size()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop(); 
		
		for(int i=0;i<4;i++){
			int ny = y+dy[i];
			int nx = x+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=n) continue;
			if(a[ny][nx] != m || visited[ny][nx]) continue;
			visited[ny][nx] = 1; 
			q.push({ny,nx});
			cnt++;
		}
	}
	
	
	return cnt;
}
int main() {
	cin >> n >> k; 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]){
				int now = bfs(i,j);
				if(now<k) continue;
				b[a[i][j]]++;
				mx = (mx>b[a[i][j]] ? mx : b[a[i][j]]);
			}
		}
	}
	
	for(int i=1;i<=30;i++){
		if(mx==b[i]) ret=i;
	}
	cout << ret <<"\n";
	return 0;
}