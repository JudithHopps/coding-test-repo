#include <bits/stdc++.h>
using namespace std;
int n, ret;
struct Board
{
  int a[24][24];

  void rotate90()
  {
    int temp[24][24];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        temp[i][j] = a[n - j - 1][i];
      }
    }
    memcpy(a, temp, sizeof(a));
    return;
  }

  void move()
  {
    int temp[24][24];
    memset(temp,0,sizeof(temp));
    for (int i = 0; i < n; i++)
    {
      int c = -1, ch = 0;
      for (int j = 0; j < n; j++)
      {
        if (a[i][j] == 0)
          continue;
        if (ch && temp[i][c] == a[i][j])
        {
          temp[i][c] *= 2;
          ch = 0;
        }
        else
        {
          temp[i][++c] = a[i][j];
          ch = 1;
        }
      }
    
    }
    memcpy(a, temp, sizeof(a));
  }

  void getMax()
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        ret = max(ret, a[i][j]);
      }
    }
  }
};

void dfs(Board b, int cnt)
{
  if (cnt == 5)
  {
    b.getMax();
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    Board d = b;
    d.move();
    dfs(d, cnt + 1);
    b.rotate90();
  }
  return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  Board b;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> b.a[i][j];
    }
  }

  dfs(b, 0);
  cout << ret << "\n";

  return 0;
}