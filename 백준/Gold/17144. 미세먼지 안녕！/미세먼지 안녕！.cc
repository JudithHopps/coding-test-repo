#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int r, c, t, a[54][54], temp[54][54], ret;
vector<pii> v1, v2;
bool flag = 1;
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};

void chung(vector<pii> &v)
{
  for (int i = v.size() - 1; i > 0; i--)
  {
    a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
  }
  a[v[0].first][v[0].second] = 0;
}

void mise()
{
  queue<pii> q;
  memset(temp, 0, sizeof(temp));

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (a[i][j] > 0)
      {
        q.push({i, j});
      }
    }
  }

  while (q.size())
  {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    int exp = a[y][x] / 5;

    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy1[i];
      int nx = x + dx1[i];
      if (ny < 0 || nx < 0 || ny >= r || nx >= c || a[ny][nx] == -1)
        continue;
      temp[ny][nx] += exp;
      a[y][x] -= exp;
    }
  }
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      a[i][j] += temp[i][j];
    }
  }
}

vector<pii> chungArea(int y, int x, int dy[], int dx[])
{
  int sy = y, sx = x;
  int i = 0;
  vector<pii> v;

  while (true)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny == sy && nx == sx)
      break;
    if (ny < 0 || nx < 0 || ny >= r || nx >= c)
    {
      i++;
      ny = y + dy[i];
      nx = x + dx[i];
    }
    if (ny == sy && nx == sx)
      break;
    y = ny, x = nx;
    v.push_back({ny, nx});
  }
  return v;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c >> t;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> a[i][j];
      if (a[i][j] == -1)
      {
        if (flag)
        {
          v1 = chungArea(i, j, dy1, dx1);
          flag = 0;
        }
        else
        {
          v2 = chungArea(i, j, dy2, dx2);
        }
      }
    }
  }

  while (t--)
  {
    mise();
    chung(v1);
    chung(v2);
  }

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (a[i][j] != -1)
        ret += a[i][j];
    }
  }
  cout << ret << "\n";
  return 0;
}