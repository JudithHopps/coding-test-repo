#include <bits/stdc++.h>
using namespace std;
int n, m, x, a, b, c, ret;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[1001], dist2[1001];
bool visited[1001];
const int INF = 987654321;
vector<pair<int, int>> adj[1001], adj2[1001];

void dijkstra(int *dist, vector<pair<int, int>> *adj)
{
  pq.push({0, x});
  dist[x] = 0;

  while (pq.size())
  {
    int here = pq.top().second;
    int here_dist = pq.top().first;
    pq.pop();

    if (here_dist != dist[here])
      continue;

    for (auto there : adj[here])
    {
      int next = there.second;
      int d = there.first;
      if (dist[next] > dist[here] + d)
      {
        dist[next] = dist[here] + d;
        pq.push({dist[next], next});
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> x;
  fill(dist, dist + 1001, INF);
  fill(dist2, dist2 + 1001, INF);

  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj2[b].push_back({c, a});
  }
  dijkstra(dist, adj);
  dijkstra(dist2, adj2);

  for (int i = 1; i <= n; i++)
  {
    if (i == x)
      continue;
    ret = max(ret, dist[i] + dist2[i]);
  }

  cout << ret << "\n";

  return 0;
}