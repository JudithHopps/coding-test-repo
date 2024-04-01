#include <bits/stdc++.h>
using namespace std;
int n, m, t, d, a[26][26], b[3000][3000];
char c;
const int INF = 987654321;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
vector<int> v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(&b[0][0], &b[0][0] + 3000 * 3000, INF);

  cin >> n >> m >> t >> d;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> c;
      if (c >= 'A' && c <= 'Z')
      {
        a[i][j] = c - 'A';
      }
      else
      {
        a[i][j] = c - 'a' + 26;
      }
      v.push_back(i * 100 + j);
    }
  }

  for (int y = 0; y < n; y++)
  {
    for (int x = 0; x < m; x++)
    {
      for (int i = 0; i < 4; i++)
      {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
          continue;

        int diff = abs(a[ny][nx] - a[y][x]);
        if (diff <= t)
        {
          if (a[y][x] < a[ny][nx])
          {
            b[y * 100 + x][ny * 100 + nx] = diff * diff;
          }
          else
            b[y * 100 + x][ny * 100 + nx] = 1;
        }
      }
    }
  }

  for (int k : v)
  {
    for (int i : v)
    {
      for (int j : v)
      {
        b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
      }
    }
  }

  int ret = a[0][0];
  for(int vv : v){
      if(d >= b[0][vv] + b[vv][0]){
          ret = max(ret,a[vv/100][vv%100]);
      }
  }
  cout << ret << "\n";

  return 0;
}