#include <bits/stdc++.h>
using namespace std;
int n, k, a[104], visited[104], ret;
const int INF = 987654321;
vector<int> v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < k; i++)
  {
    if (!visited[a[i]])
    {
      if (v.size() == n)
      {
        int mxIdx = -1, del = -1;
        for (int vv : v)
        {
          int idx = INF;
          for (int j = i + 1; j < k; j++)
          {
            if (vv == a[j])
            {
              idx = j;
              break;
            }
          }
          if (mxIdx < idx)
          {
            mxIdx = idx;
            del = vv;
          }
        }
        v.erase(find(v.begin(), v.end(), del));
        visited[del] = 0;
        ret++;
      }
      v.push_back(a[i]);
      visited[a[i]] = 1;
    }
  }
  cout << ret << "\n";

  return 0;
}