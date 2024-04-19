#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef vector<pair<int, int>> vpi;
const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };
vpi cctv;

const int INF = 987654321;
int n, m, a[10][10], ret = INF;

int cal() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) cnt++; // 감시되지 않는 영역만 카운트
		}
	}
	return cnt;
}
bool in(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= m) return false;
	return true;
}
vpi go(int idx, int d) {
	int y = cctv[idx].first;
	int x = cctv[idx].second;
	
	int cctvType = a[y][x];
	vpi now;
	if (cctvType == 1) {
		int ny = y;
		int nx = x;
		while (true) {
			ny += dy[(d + 1) % 4];
			nx += dx[(d + 1) % 4];
			if (in(ny, nx) && a[ny][nx] != -1) {
				if (a[ny][nx] == 0) {
					a[ny][nx] = -10; // 감시 영역 표시
					now.push_back({ ny,nx });
				}
			}
			else break;
		}
	}

	else if (cctvType == 2) {
		for (int i = 0; i <= 2; i+=2) { 
			int ny = y, nx = x;
			while (true) {
				ny += dy[(d + i) % 4];
				nx += dx[(d + i) % 4];
				if (in(ny, nx) && a[ny][nx] != -1) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = -10; // 감시 영역 표시
						now.push_back({ ny,nx });
					}
				}
				else break;
			}
		}
	}
	else {
		for (int i = 0; i < cctvType-1; i ++) {
			int ny = y, nx = x;
			while (true) {
				ny += dy[(d + i) % 4];
				nx += dx[(d + i) % 4];
				if (in(ny, nx) && a[ny][nx] != -1) {
					if (a[ny][nx] == 0) {
						a[ny][nx] = -10; // 감시 영역 표시
						now.push_back({ ny,nx });
					}
				}
				else break;
			}
		}
	}

	return now;
}	

void dfs(int idx) {
	if (idx == cctv.size()) {
		ret = min(ret, cal());
		return;
	}
	for (int k = 0; k < 4; k++) {
		vpi now = go(idx, k);
		dfs(idx + 1);
		for (auto it : now) {
			a[it.first][it.second] = 0;
		}
	}
}
int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 6) a[i][j] = -1;
			if (a[i][j] > 0) {
				cctv.push_back({ i,j });
			}
		}
	}
	//cout << "dfs 전 \n";
	dfs(0);

	cout << ret << "\n";
	return 0;
}
