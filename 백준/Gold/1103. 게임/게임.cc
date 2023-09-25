#include <bits/stdc++.h>
using namespace std;
int m, n, dp[54][54];
string s;
char b[54][54];
bool check[54][54];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

bool in(int aa, int bb)
{
  return (1 <= aa && aa <= m && bb >= 1 && bb <= n);
}

int down(int y, int x)
{
  if (!in(y, x) || b[y][x] == 'H')
    return 0;
  if (check[y][x])
  {
    cout << -1 << "\n";
    exit(0);
  }
  int &ret = dp[y][x];
  if (ret)
    return ret;

  check[y][x] = 1;
  int value = (int)b[y][x] - '0';
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i] * value;
    int nx = x + dx[i] * value;
    ret = max(ret, down(ny, nx) + 1);
  }
  check[y][x] = 0;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;
  for (int i = 1; i <= m; i++)
  {
    cin >> s;
    for (int j = 1; j <= n; j++)
    {
      b[i][j] = s[j - 1];
    }
  }

  cout << down(1, 1) << "\n";
  return 0;
}