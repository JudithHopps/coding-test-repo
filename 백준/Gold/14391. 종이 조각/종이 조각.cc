#include <bits/stdc++.h>
using namespace std;
int n, m, ret, temp, a[4][4];

int main()
{
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%1d", &a[i][j]);
    }
  }

  for (int k = 0; k < (1 << (n * m)); k++)
  {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      int cur = 0;
      for (int j = 0; j < m; j++)
      {
        int x = m * i + j;
        if ((k & (1 << x)) == 0)
        {
          cur = cur * 10 + a[i][j];
        }
        else
        {
          sum += cur;
          cur = 0;
        }
      }
      sum += cur;
    }

    for (int j = 0; j < m; j++)
    {
      int cur = 0;
      for (int i = 0; i < n; i++)
      {
        int x = i * m + j;
        if (k & (1 << x))
        {
          cur = cur * 10 + a[i][j];
        }
        else
        {
          sum += cur;
          cur = 0;
        }
      }
      sum += cur;
    }

    ret = max(ret, sum);
  }

  printf("%d", ret);
  return 0;
}