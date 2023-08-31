#include <bits/stdc++.h>
using namespace std;
int n, a[14][14], visited[14][14], ret;
const int dy[5] = {0, 0, 0, 1, -1}, dx[5] = {0, -1, 1, 0, 0};

void go(int y, int x, int cnt, int sum)
{
  if (y == n - 1 || x == n - 1)
    return;

  if (cnt == 3)
  {
    ret = min(ret, sum);
    return;
  }

  for (int i = 1; i < n - 1; i++)
  {
    for (int j = 1; j < n - 1; j++)
    {
      bool flag = true;
      for (int k = 0; k < 5; k++)
      {
        int ny = i + dy[k];
        int nx = j + dx[k];
        if (visited[ny][nx])
        {
          flag = false;
          break;
        }
      }
      if (flag)
      {

        int temp = sum;
        for (int k = 0; k < 5; k++)
        {
          int ny = i + dy[k];
          int nx = j + dx[k];
          visited[ny][nx] = 1;
          temp += a[ny][nx];
        }
        go(i, j, cnt + 1, temp);

        for (int k = 0; k < 5; k++)
        {
          int ny = i + dy[k];
          int nx = j + dx[k];
          visited[ny][nx] = 0;
        }
      }
      // for (int i = 0; i < n; i++)
      // {
      //   for (int j = 0; j < n; j++)
      //   {
      //     cout << visited[i][j] << " ";
      //   }
      //   cout << "\n";
      // }
      // cout << "\n\n";
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      ret += a[i][j];
    }
  }

  go(0, 0, 0, 0);

  cout << ret << "\n";

  return 0;
}