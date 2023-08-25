#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 666;; i++)
  {
    if (to_string(i).find("666") != string::npos)
    {
      n--;
      if (n == 0)
      {
        cout << i << "\n";
        break;
      }
    }
  }
  return 0;
}