#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
const int INF = 987654321;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m, k, a[104][104], b[104][104], ret = INF, r, c, s, visited[104][104], dir, sy, sx, ey, ex;
vector<pair<int, int>> vv;
vector<int> v_idx;
struct A
{
  int y, x, s;
};
vector<A> v;

void go(int y, int x, int first)
{
  if (!first && y == sy && x == sx)
    dir++;
  if (!first && y == sy && x == ex)
    dir++;
  if (!first && y == ey && x == ex)
    dir++;
  if (!first && y == ey && x == sx)
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
    sy = y - i;
    sx = x - i;
    ey = y + i;
    ex = x + i;
    vv.clear();
    dir = 0;
    memset(visited, 0, sizeof(visited));
    visited[sy][sx] = 1;
    vv.push_back({sy, sx});
    go(sy, sx, 1);
    vector<int> vvv;
    for (pair<int, int> c : vv)
      vvv.push_back(b[c.f][c.s]);
    rotate(vvv.begin(), vvv.begin() + vvv.size() - 1, vvv.end());
    for (int i = 0; i < vv.size(); i++)
      b[vv[i].f][vv[i].s] = vvv[i];
  }
}
int solve()
{
  for (int i : v_idx)
    rotateAll(v[i].y, v[i].x, v[i].s);
  int _ret = INF;
  for (int i = 0; i < n; i++)
  {
    int s = 0;
    for (int j = 0; j < m; j++)
      s += b[i][j];
    _ret = min(_ret, s);
  }
  return _ret;
}
int main()
{
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
    r--;
    c--;
    v.push_back({r, c, s});
    v_idx.push_back(i);
  }
  do
  {
    memcpy(b, a, sizeof(b));
    ret = min(ret, solve());
  } while (next_permutation(v_idx.begin(), v_idx.end()));
  cout << ret << "\n";
  return 0;
}