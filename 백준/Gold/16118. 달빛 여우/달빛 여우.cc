#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, bool> TI;
struct A
{
  int dist, here, flag;
};
int n, m, a, b, d, dist_wolf[4001][2], dist_fox[4001], ret;
vector<pair<int, int>> adj[4001];
const int INF = 987654321;
void dijkstra_fox()
{
  fill(dist_fox, dist_fox + 4001, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist_fox[1] = 0;
  pq.push({0, 1});

  while (pq.size())
  {
    int here = pq.top().second;
    int here_dist = pq.top().first;
    pq.pop();

    if (dist_fox[here] != here_dist)
      continue;

    for (auto there : adj[here])
    {
      int next = there.first;
      int d = there.second;
      if (dist_fox[next] > dist_fox[here] + d)
      {
        dist_fox[next] = dist_fox[here] + d;
        pq.push({dist_fox[next], next});
      }
    }
  }
}

void dijkstra_wolf()
{
  fill(&dist_wolf[0][0], &dist_wolf[0][0] + 4001 * 2, INF);
  dist_wolf[1][0] = 0;

  priority_queue<TI, vector<TI>, greater<TI>> pq;
  pq.push({0, 1, 0});

  while (pq.size())
  {
    int dist, here, flag;
    tie(dist, here, flag) = pq.top();
    pq.pop();

    if (dist != dist_wolf[here][flag])
      continue;

    for (auto there : adj[here])
    {
      int next = there.first;
      int d = !flag ? there.second / 2 : there.second * 2;

      if (dist_wolf[next][!flag] > dist_wolf[here][flag] + d)
      {
        dist_wolf[next][!flag] = dist_wolf[here][flag] + d;
        pq.push({dist_wolf[next][!flag], next, !flag});
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> d;
    adj[a].push_back({b, d * 2});
    adj[b].push_back({a, d * 2});
  }

  dijkstra_fox();
  dijkstra_wolf();

  for (int i = 2; i <= n; i++)
  {
    int d = min(dist_wolf[i][0], dist_wolf[i][1]);
    if (d > dist_fox[i])
      ret++;
  }

  cout << ret << "\n";

  return 0;
}