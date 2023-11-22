#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, v[100004], visited[100004], flag;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    v[a]++, v[b]--;
  }

  for (int i = 1; i <= n; i++)
  {
    v[i] += i;
    visited[v[i]]++;
  }

  for (int i = 1; i <= n; i++)
  {
    if (visited[i] >= 2)
    {
      flag = 1;
      break;
    }
  }

  if (flag)
    cout << -1 << "\n";
  else
  {
    for (int i = 1; i <= n; i++)
    {
      cout << v[i] << " ";
    }
  }
  return 0;
}