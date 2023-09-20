#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ret, n, attack, t, a, h, H, mxH, damage;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> attack;
  for (int i = 0; i < n; i++)
  {
    cin >> t >> a >> h;
    if (t == 1)
    {
      damage = a * (ceil((double)h / attack) - 1);
      if (H < damage)
      {
        mxH += damage - H;
        H = 0;
      }
      else
      {
        H -= damage;
      }
    }
    else
    {
      attack += a;
      H = min(mxH, H + h);
    }
  }

  cout << mxH + 1 << "\n";

  return 0;
}