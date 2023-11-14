#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, s, e;
int a[504][504], dist[504];
const int INF = 987654321;

void dijkstra()
{
  fill(dist, dist + 504, INF);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  dist[s] = 0;

  while (pq.size())
  {
    int here = pq.top().second;
    int here_dist = pq.top().first;
    pq.pop();

    if (here_dist != dist[here])
      continue;

    for (int i = 0; i < n; i++)
    {
      if (a[here][i] == -1)
        continue;
      int d = a[here][i];
      if (dist[i] > dist[here] + d)
      {
        dist[i] = dist[here] + d;
        pq.push({dist[i], i});
      }
    }
  }
}

void eraseEdge()
{
  queue<int> q;
  q.push(e);

  while (q.size())
  {
    int here = q.front();
    q.pop();

    for (int i = 0; i < n; i++)
    {
      if (a[i][here] == -1)
        continue;
      if (dist[here] == dist[i] + a[i][here])
      {
        a[i][here] = -1;
        q.push(i);
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true)
  {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    cin >> s >> e;
    memset(a, -1, sizeof(a));

    for (int i = 0; i < m; i++)
    {
      cin >> x >> y >> z;
      a[x][y] = z;
    }

    dijkstra();
    eraseEdge();
    dijkstra();

    cout << (dist[e] == INF ? -1 : dist[e]) << "\n";
  }

  return 0;
}