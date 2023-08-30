#include <bits/stdc++.h>
using namespace std;
int n, visited[10];
char a[10];
vector<int> v;
vector<vector<int>> ret;

bool check(int a, char b, int c)
{
  return b == '<' ? a < c : a > c;
}

void isAnswer(vector<int> v)
{
  bool flag = true;
  for (int i = 0; i < n; i++)
  {
    if (!check(v[i], a[i], v[i + 1]))
    {
      flag = false;
      break;
    };
  }

  if (flag)
  {
    ret.push_back(v);
  }
}

void dfs(vector<int> v, int size)
{
  if (size == n + 1)
  {
    isAnswer(v);
    return;
  }

  for (int i = 0; i < 10; i++)
  {
    if (!visited[i])
    {
      visited[i] = 1;
      v.push_back(i);

      dfs(v, size + 1);

      visited[i] = 0;
      v.pop_back();
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < 10; i++)
  {
    visited[i] = 1;
    dfs({i}, 1);
    visited[i] = 0;
  }

  for (int i : ret[ret.size() - 1])
  {
    cout << i;
  }
  cout << "\n";

  for (int i : ret[0])
  {
    cout << i;
  }
  cout << "\n";

  return 0;
}