#include <bits/stdc++.h>
using namespace std;
int h, w, cur, a[104][104], ret[104][104];

string s;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> h >> w;
  for (int i = 0; i < h; i++)
  {

    cin >> s;
    cur = 0;
    for (int j = 0; j < w; j++)
    {
      a[i][j] = s[j];
      // cout << a[i][j] << " ";

      if (a[i][j] == 97 + 2)
      {
        ret[i][j] = 0;
        cur = j + 1;
      }
      else if (cur == 0)
        ret[i][j] = -1;
      else
      {
        ret[i][j] = j - cur + 1;
      }
    }
  }

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cout << ret[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}