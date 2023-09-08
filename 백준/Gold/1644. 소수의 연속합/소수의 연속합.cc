#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, cnt, sum, hi, lo, ret, a[2000001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 2; i <= n; i++)
  {
    bool flag = true;

    for (int j = 2; j * j <= i; j++)
    {
      if (i % j == 0)
      {
        flag = false;
        break;
      }
    }

    if (flag)
    {
      v.push_back(i);
    }
  }

  while (1)
  {
    if (sum >= n)
      sum -= v[lo++];
    else if (hi == v.size())
      break;
    else
      sum += v[hi++];
    if (sum == n)
      ret++;
  }
  cout << ret << "\n";
}