
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const long long INF = -1e18;
long long  dist[54], money[54];
int n, s, e, m,a,b,c,visited[54];
vector<pair<int,int>> adj[54];
queue<int> q;
bool ok=false;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}
	fill(dist, dist + 54, INF);
	dist[s] = money[s];

	for (int i = 0; i < n; i++) {
		for (int here = 0; here < n; here++) {
			for (auto there : adj[here]) {
				int next = there.first;
				int d = there.second;
				if (dist[here] != INF && dist[next] < dist[here] + money[next] - d) {
					dist[next] = dist[here] + money[next] - d;
					if (i == n - 1) {
						q.push(here);
					}
				}
			}
		}
	}
	

	while (q.size()) {
		int here = q.front();
		q.pop();

		for (auto there : adj[here]) {
			int next = there.first;
			if (next == e) {
				ok = 1;
				break;
			}
			if (!visited[next]) {
				visited[next] = 1;
				q.push(next);
			}
		}
		if (ok) break;
	}

	if (ok) {
		cout << "Gee\n";
	}
	else if (dist[e] == INF) {
		cout << "gg\n";
	}
	else {
		cout << dist[e] << "\n";
	}

	return 0;
}
