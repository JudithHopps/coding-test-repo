#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int dy[] = { 0,-1,0,1 }, dx[] = { 1,0,-1,0 };
const int dy2[] = { 0,1,0,-1 }, dx2[] = { 1,0,-1,0 };

int R, C, T, a[54][54], temp[54][54], ret,y,x;
vector<pair<int,int>> v1, v2;

void dfs(int y, int x, int d,const int *dy, const int *dx, vector<pair<int, int>> &v) {
	if (a[y][x] == -1)return;
	
	v.push_back({ y,x });

	int ny = y + dy[d];
	int nx = x + dx[d];

	if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
		d = (d + 1) % 4;
		ny = y + dy[d];
		nx = x + dx[d];
	}

	dfs(ny, nx, d, dy, dx, v);

}
void findRoute() {
	dfs(y-1, x+1, 0,dy, dx,v1);
	dfs(y, x+1, 0,dy2, dx2, v2);

	
}
void mise() {
	memset(temp, 0, sizeof(temp));
	for (int y = 0; y < R; y++) {
		for (int x= 0; x < C; x++) {
			if (a[y][x] <= 0)continue;
			int q = a[y][x] / 5;

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
				if (a[ny][nx] == -1) continue;
				temp[ny][nx] += q;
				temp[y][x] -= q;
			}
		}
	}
}
void reOrder() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (a[y][x] == -1)continue;
			a[y][x] += temp[y][x];
		}
	}
}
void cleanAir(vector<pair<int, int>> &v) {
	vector<int> temp;

	for (int i = 0; i < v.size()-1; i++) {
		temp.push_back(a[v[i].first][v[i].second]);
	}

	for (int i = 1; i < v.size(); i++) {
		a[v[i].first][v[i].second] = temp[i - 1];
	}
	a[v[0].first][v[0].second] = 0;
}
void print(int arr[][54]) {
	
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cout << arr[y][x] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int main()
{
	//freopen("미세먼지.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				y = i, x = j;
			}
		}
	}

	// 공기 청정기 경로 찾기
	findRoute();

	/*for (auto it : v1) {
		cout << it.first << " , " << it.second << "\n";
	}*/

	while (T--) {
		mise();
		//print(temp);
		reOrder(); 

		//print(a);
		cleanAir(v1);
		cleanAir(v2);
		//print(a);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (a[i][j] > 0) {
				ret += a[i][j];
			}
			
		}
	}

	cout << ret << "\n";
	return 0;
}
