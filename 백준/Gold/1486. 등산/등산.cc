#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int n, m, T, D, h[30][30], cost[3000][3000];
char c;
const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> T >> D;
	fill(&cost[0][0], &cost[0][0] + 3000 * 3000, INF);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c >= 'A' && c <= 'Z') {
				h[i][j] = c - 'A';
			}
			else {
				h[i][j] = c - 'a' + 26;
			}
			v.push_back( i * 100 + j );
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int d = 0; d < 4; d++) {

				int ny = i + dy[d];
				int nx = j + dx[d];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				int diff = abs(h[i][j] - h[ny][nx]);
				if (diff <= T) {
					if(h[i][j] >= h[ny][nx])
						cost[i * 100 + j][ny * 100 + nx] = 1;
					else
						cost[i * 100 + j][ny * 100 + nx] = diff * diff;
				}
				
			}

		}
	}
	for (int k: v) {
		for (int i : v) {
			for (int j:v) {
				if (cost[i][j] > cost[i][k] + cost[k][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}

	int ret = h[0][0];
	for (int k : v) {
		if(D >= cost[0][k] + cost[k][0])
			ret = max(ret, h[k / 100][k % 100]);
	}
	cout << ret << "\n";

	return 0;
}