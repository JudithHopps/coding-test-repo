#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, s[24][24], ret = INF;

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
      cin >> s[i][j];
    }
  }

  for (int i = 1; i < (1 << n); i++)
  {
    if (__builtin_popcount(i) != n / 2)
      continue;
    vector<int> A, B;
    for (int j = 0; j < n; j++)
    {
      if (i & (1 << j))
      {
        A.push_back(j);
      }
      else
      {
        B.push_back(j);
      }
    }
    int asum = 0, bsum = 0;
    for (int i = 0; i < n / 2; i++)
    {
      for (int j = 0; j < n / 2; j++)
      {
        if (i == j)
          continue;
        asum += s[A[i]][A[j]];
        bsum += s[B[i]][B[j]];
      }
    }
    ret = min(ret, abs(asum - bsum));
    if (ret == 0)
      break;
  }

  cout << ret << "\n";

  return 0;
}