#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m, k, a[54][54], visited[54][54], b[54][54], r, c, s, ret = INF, sy, sx, ey, ex, dir;
struct A
{
  int r, c, s;
};
vector<A> v;
vector<int> v_idx;
vector<pair<int, int>> vv;

void go(int y, int x, int first)
{
  if (!first && y == sy && x == sx)
    dir++;
  if (!first && y == sy && x == ex)
    dir++;
  if (!first && y == ey && x == sx)
    dir++;
  if (!first && y == ey && x == ex)
    dir++;

  int ny = y + dy[dir];
  int nx = x + dx[dir];
  if (visited[ny][nx])
    return;

  visited[ny][nx] = 1;
  vv.push_back({ny, nx});
  go(ny, nx, 0);
}
void rotateAll(int y, int x, int s)
{
  for (int i = s; i > 0; i--)
  {
    memset(visited, 0, sizeof(visited));
    vv.clear();
    dir = 0;
    sy = y - i;
    sx = x - i;
    ey = y + i;
    ex = x + i;

    visited[sy][sx] = 1;
    vv.push_back({sy, sx});
    go(sy, sx, 1);

    vector<int> vvv;
    for (auto it : vv)
    {
      vvv.push_back(b[it.first][it.second]);
    }
    rotate(vvv.begin(), vvv.begin() + vvv.size() - 1, vvv.end());
    for (int i = 0; i < vv.size(); i++)
    {
      b[vv[i].first][vv[i].second] = vvv[i];
    }
  }
}
int solve()
{
  int ret = INF;
  for (auto i : v_idx)
  {
    rotateAll(v[i].r, v[i].c, v[i].s);
  }
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
      sum += b[i][j];
    }
    ret = min(sum, ret);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < k; i++)
  {
    cin >> r >> c >> s;
    r--, c--;
    v.push_back({r, c, s});
    v_idx.push_back(i);
  }

  do
  {
    memcpy(b, a, sizeof(a));
    ret = min(ret, solve());
  } while (next_permutation(v_idx.begin(), v_idx.end()));

  cout << ret << "\n";
  return 0;
}