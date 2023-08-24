#include <bits/stdc++.h>
using namespace std;
int n, ret, i = 666;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 666;;)
  {
    if (to_string(i).find("666") != string::npos)
    {
      ret = i;
      n--;
      if (n == 0)
        break;
    }
    i++;
  }
  cout << ret << "\n";
  return 0;
}