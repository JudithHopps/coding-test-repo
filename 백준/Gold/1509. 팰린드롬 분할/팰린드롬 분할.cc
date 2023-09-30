#include <bits/stdc++.h>
using namespace std;
string str;
int dp[2504][2504], dp2[2504];
const int INF = 987654321;

int go(int pos)
{
  if (pos == str.size())
    return 0;
  int &ret = dp2[pos];
  if (ret != INF)
    return ret;

  for (int size = 1; pos + size <= str.size(); size++)
  {
    if (dp[pos][size])
    {
      ret = min(ret, go(pos + size) + 1);
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;
  for (int i = 0; i < str.size(); i++)
  {
    dp[i][1] = 1;
    if (str[i] == str[i + 1])
      dp[i][2] = 1;
  }

  for (int size = 3; size <= str.size(); size++)
  {
    for (int i = 0; i + size <= str.size(); i++)
    {
      if (str[i] == str[i + size - 1] && dp[i + 1][size - 2])
      {
        dp[i][size] = 1;
      }
    }
  }

  fill(dp2, dp2 + 2504, INF);

  cout << go(0) << "\n";
  return 0;
}