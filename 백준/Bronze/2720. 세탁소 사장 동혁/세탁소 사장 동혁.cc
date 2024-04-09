#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[8];
int coin[] = {25, 10, 5, 1};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--)
  {
    cin >> n;
    // n *= 100;

    for (int i = 0; i < 4; i++)
    {
      if (n == 0)
        continue;
      a[i] = n / coin[i];
      n = n % coin[i];
    }
    for (int i = 0; i < 4; i++)
    {
      cout << a[i] << " ";
      a[i] = 0;
    }
    cout << "\n";
  }

  return 0;
}