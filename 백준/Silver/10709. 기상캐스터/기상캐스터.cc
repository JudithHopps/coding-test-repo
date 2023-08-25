#include <bits/stdc++.h>
using namespace std;
int h, w, pre;
string str;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> h >> w;
  for (int i = 0; i < h; i++)
  {
    cin >> str;
    pre = 0;
    for (int j = 0; j < w; j++)
    {
      char b = str[j];
      if (b == 'c')
      {
        cout << 0 << " ";
        pre = j + 1;
      }
      else if (pre)
      {
        cout << j - pre + 1 << " ";
      }
      else if (pre == 0)
      {
        cout << -1 << " ";
      }
    }
    cout << "\n";
    }

  return 0;
}