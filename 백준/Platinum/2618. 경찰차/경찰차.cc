#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, w, x[1004], y[1004], dp[1004][1004];

int dist(int a, int b)
{
  return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}
int go(int a, int b)
{
  if (a == w + 1 || b == w + 1)
  {
    return 0;
  }

  int &ret = dp[a][b];
  if (ret != INF)
    return ret;

  int next = max(a, b) + 1;
  return ret = min(go(next, b) + dist(a, next), go(a, next) + dist(b, next));
}
void print()
{
  int a = 0, b = 1;

  for (int i = 2; i < w + 2; i++)
  {
    // cout << dp[a][b] << "   :  " << dp[i][b] + dist(a, i) << "   :   " << dp[a][i] + dist(b, i) << "\n";
    if (dp[i][b] + dist(a, i) < dp[a][i] + dist(b, i))
    {
      cout << "1\n";
      a = i;
    }
    else
    {
      cout << "2\n";
      b = i;
    }
  }
  return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> w;
  x[0] = 1, y[0] = 1;
  x[1] = n, y[1] = n;

  fill(&dp[0][0], &dp[0][0] + 1004 * 1004, INF);
  for (int i = 2; i < w + 2; i++)
  {
    cin >> y[i] >> x[i];
  }

  cout << go(0, 1) << "\n";
  print();

  return 0;
}