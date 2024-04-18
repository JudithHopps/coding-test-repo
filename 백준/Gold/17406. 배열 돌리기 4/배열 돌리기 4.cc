#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>> pairV;
vector<int> v;
vector<int> idx;
int ret=987654321, n, m, k, a[54][54],b[54][54], r[10], c[10], s[10],d,sy,sx,ey,ex,visited[54][54];
const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };

void getMax() {
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += a[i][j];
		}
		ret = min(ret, sum);
	}
}
void print() {
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
void dfs(int y, int x) {
	pairV.push_back({ y,x });
	v.push_back(a[y][x]);
	visited[y][x] = 1;


	if (y == sy && x == ex) d++;
	if (y == ey && x == ex) d++;
	if (y == ey && x == sx) d++;

	int ny = y + dy[d];
	int nx = x + dx[d];

	if (visited[ny][nx]) return;
	dfs(ny, nx);
}
void rot(int y, int x, int s) {
	for (int i = 1; i <= s; i++) {
		memset(visited, 0, sizeof(visited));
		sy = y - i;	ey = y +i;
		sx = x - i; ex = x +i;
		d = 0; 
		v.clear();
		pairV.clear();

		dfs(sy, sx);

		//cout << "\n";
		rotate(v.begin(), v.end()-1,v.end());
		for (int i = 0; i < pairV.size();i++) {
			a[pairV[i].first][pairV[i].second] = v[i];
		}

		//print();
	}
}
void solve() {
	memcpy(a,b, sizeof(a));

	for (int i : idx) {
		rot(r[i] - 1, c[i] - 1, s[i]);
	}
	getMax();
}
int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		idx.push_back(i);
		cin >> r[i] >> c[i] >> s[i];
	}
	
	do {
		solve();
	} while (next_permutation(idx.begin(), idx.end()));

	cout << ret << "\n";

	return 0;
}
