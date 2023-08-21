#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;

ll go(ll n, ll d)
{
  if (d == 1)
    return (n * d) % c;

  ll ret = go(n, d / 2);
  ret = (ret * ret) % c;
  if (d % 2)
  {
    ret = ret * a % c;
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> c;
  cout << go(a, b) << "\n";

  return 0;
}