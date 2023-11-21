#include <bits/stdc++.h>
using namespace std;
int n, m, x, a, b, c, dist[1001][1001];
const int INF = 987654321;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&dist[a][b], &dist[a][b] + 1001 * 1001, INF);

  cin >> n >> m >> x;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> c;
    dist[a][b] = c;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (dist[i][k] + dist[k][j] < dist[i][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  int ret = 0;
  for (int i = 1; i <= n; i++)
  {
    if (i == x)
      continue;
    ret = max(ret, dist[i][x] + dist[x][i]);
  }
  cout << ret << "\n";

  return 0;
}