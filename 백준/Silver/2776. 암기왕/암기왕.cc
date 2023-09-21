#include <bits/stdc++.h>
using namespace std;
int t, n, m, b[1000004], l, r;
vector<int> ret;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--)
  {

    fill(b, b + 1000004, 0);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
      cin >> b[i];
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++)
    {
      bool flag = 0;
      l = 0, r = n - 1;
      while (l <= r)
      {
        int mid = (l + r) / 2;
        if (a[mid] > b[i])
        {
          r = mid - 1;
        }
        else if (a[mid] == b[i])
        {
          flag = 1;
          break;
        }
        else
        {
          l = mid + 1;
        }
      }
      cout << (flag ? 1 : 0) << "\n";
    }
  }

  return 0;
}