#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 987654321;
int t,n, a[130][130], dist[130][130];
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (1) {
		t++;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		fill(&dist[0][0], &dist[0][0] + 130*130, INF);
		dist[0][0] = a[0][0];
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ dist[0][0],0 });

		while (pq.size()) {
			int y = pq.top().second/200;
			int x = pq.top().second%200;
			int d = pq.top().first;
			pq.pop();

			if (dist[y][x] != d) continue;

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (dist[ny][nx] > d + a[ny][nx]) {
					dist[ny][nx] = d+ a[ny][nx];
					pq.push({ dist[ny][nx],ny * 200 + nx });
				}
			}
		}
		int ret = dist[n-1][n-1];
		cout << "Problem " << t << ": " << ret << "\n";
	}
	return 0;
}
