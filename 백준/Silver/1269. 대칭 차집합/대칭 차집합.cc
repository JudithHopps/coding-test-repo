#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, t;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  vector<int> a(n + m), b(m);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> a[n + i];
  }
  sort(a.begin(), a.end());

  int cnt = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (i == a.size() - 1)
      cnt++;
    if (i < a.size() - 1 && a[i] != a[i + 1])
    {
      cnt++;
    }
    else
    {
      i++;
    }
  }
  cout << cnt << "\n";

  return 0;
}