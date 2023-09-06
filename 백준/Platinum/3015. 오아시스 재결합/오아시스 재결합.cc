#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<pair<ll, ll>> st;
ll ret, n, temp;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    int cnt = 1;
    while (st.size() && st.top().first <= temp)
    {
      ret += st.top().second;
      if (st.top().first == temp)
      {
        cnt = st.top().second + 1;
      }
      else
      {
        cnt = 1;
      }
      st.pop();
    }

    if (st.size())
      ret++;
    st.push({temp, cnt});
  }

  cout << ret << "\n";

  return 0;
}