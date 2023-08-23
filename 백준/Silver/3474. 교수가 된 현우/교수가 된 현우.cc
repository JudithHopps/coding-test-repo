#include <bits/stdc++.h>
using namespace std;
int t, n;
int cnt2, cnt5;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;

  while (t--)
  {
    cin >> n;

    for (int i = 2; i <= n; i *= 2)
    {
      cnt2 = 0;
      cnt5 = 0;

      for (int k = 5; k <= n; k *= 5)
      {
        cnt5 += n / k;
      }
    }
    cout << cnt5 << "\n";
  }
  return 0;
}