#include <bits/stdc++.h>
using namespace std;
int t, n;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--)
  {
    cin >> n;
    int cnt2 = 0, cnt5 = 0;
    for (int i = 2; i <= n; i *= 2)
    {
      cnt2 += n / i;
    }
    for (int j = 5; j <= n; j *= 5)
    {
      cnt5 += n / j;
    }
    cout << min(cnt2, cnt5) << "\n";
  }

  return 0;
}