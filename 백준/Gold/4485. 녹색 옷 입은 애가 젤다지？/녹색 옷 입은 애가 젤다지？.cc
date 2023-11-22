#include <bits/stdc++.h>
using namespace std;
int t, n, a[130][130], dist[130][130];
const int INF = 987654321;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (++t)
  {
    scanf("%d", &n);
    if (n == 0)
      break;

    fill(&a[0][0], &a[0][0] + 130 * 130, 0);
    fill(&dist[0][0], &dist[0][0] + 130 * 130, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        scanf("%d", &a[i][j]);
      }
    }
    pq.push({a[0][0], 0});
    dist[0][0] = a[0][0];

    while (pq.size())
    {
      int y = pq.top().second / 1000;
      int x = pq.top().second % 1000;
      int here_dist = pq.top().first;
      pq.pop();
      if (here_dist != dist[y][x])
        continue;

      for (int i = 0; i < 4; i++)
      {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
          continue;

        int d = a[ny][nx];
        if (dist[ny][nx] > dist[y][x] + d)
        {
          dist[ny][nx] = dist[y][x] + d;
          pq.push({dist[ny][nx], ny * 1000 + nx});
        }
      }
    }

    printf("Problem %d: %d\n", t, dist[n - 1][n - 1]);
  }
  return 0;
}