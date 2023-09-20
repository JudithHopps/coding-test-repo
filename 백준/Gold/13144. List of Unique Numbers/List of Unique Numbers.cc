#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[100004], ret, cnt[100004], s, e;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  while (e < n)
  {
    if (cnt[a[e]])
    {
      ret += (e - s);
      cnt[a[s++]]--;
    }
    else
    {
      cnt[a[e++]]++;
    }
  }

  ret += (e - s) * (e - s + 1) / 2;
  cout << ret << "\n";

  return 0;
}