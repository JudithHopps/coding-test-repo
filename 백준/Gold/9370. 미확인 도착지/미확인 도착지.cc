#include <bits/stdc++.h>
using namespace std;
int T, dist[2004], n, m, t, s, g, h, a, b, d;
const int INF = 987654322;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--)
  {
    cin >> n >> m >> t >> s >> g >> h;
    vector<pair<int, int>> adj[2004];
    fill(dist, dist + 2004, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    for (int i = 0; i < m; i++)
    {

      cin >> a >> b >> d;
      d *= 2;
      if (a == g && b == h)
        d--;
      if (a == h && b == g)
        d--;
      adj[a].push_back({d, b});
      adj[b].push_back({d, a});
    }

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
    int candi[t + 1];
    for (int i = 0; i < t; i++)
    {
      cin >> candi[i];
    }

    sort(candi, candi + t);

    for (int i = 0; i < t; i++)
    {
      if (dist[candi[i]] % 2)
        cout << candi[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}