#include <bits/stdc++.h>
using namespace std;
int n, s, e, m, visited[104], candi[104], a, b, c, ok;
vector<pair<int, int>> adj[104];
long long dist[104], cost[104];
const long long INF = -1e18;
queue<int> q;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> s >> e >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  for (int i = 0; i < n; i++)
  {
    cin >> cost[i];
  }

  fill(dist, dist + n, INF);
  dist[s] = cost[s];

  for (int i = 0; i < n; i++)
  {
    for (int here = 0; here < n; here++)
    {
      for (auto there : adj[here])
      {
        int next = there.first;
        int d = there.second;
        if (dist[here] != INF && dist[next] < dist[here] + cost[next] - d)
        {
          dist[next] = dist[here] + cost[next] - d;
          if (i == n - 1)
            q.push(here);
        }
      }
    }
  }

  while (q.size())
  {
    int here = q.front();
    q.pop();
    for (pair<int, int> there : adj[here])
    {
      if (there.first == e)
      {
        ok = 1;
        break;
      }
      if (!visited[there.first])
      {
        visited[there.first] = 1;
        q.push(there.first);
      }
    }
    if (ok)
      break;
  }

  if (ok)
    cout << "Gee\n";
  else if (dist[e] == INF)
  {
    cout << "gg\n";
  }
  else
  {
    cout << dist[e] << "\n";
  }
  return 0;
}