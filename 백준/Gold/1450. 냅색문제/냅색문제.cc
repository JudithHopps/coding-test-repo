#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c, a[34], ret;
vector<int> v1, v2;

void go(int s, int e, vector<int> &v, int sum)
{
  if (sum > c)
    return;
  if (s == e)
  {
    v.push_back(sum);
    return;
  }

  go(s + 1, e, v, sum + a[s]);
  go(s + 1, e, v, sum);
  return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> c;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  go(0, n / 2, v1, 0);
  go(n / 2, n, v2, 0);

  sort(v2.begin(), v2.end());

  for (int b : v1)
  {
    if (c >= b)
    {
      ret += ((int)(upper_bound(v2.begin(), v2.end(), c - b) - v2.begin()));
    }
  }
  cout << ret << "\n";

  return 0;
}