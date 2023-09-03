#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<vector<int>> ret;
char a[15];

bool oper(int a, char b, int c)
{
  if (b == '<')
    return a < c;
  else
    return a > c;
}
void ch(vector<int> &v)
{
  bool flag = true;
  for (int i = 0; i < k; i++)
  {
    if (!oper(v[i], a[i], v[i + 1]))
    {
      flag = false;
      break;
    }
  }
  if (flag)
  {
    ret.push_back(v);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> a[i];
  }

  do
  {
    ch(v);

  } while (next_permutation(v.begin(), v.end()));

  sort(ret.begin(), ret.end());
  for (int i = 0; i < k + 1; i++)
  {
    cout << ret[ret.size() - 1][i] << "";
  }
  cout << "\n";
  for (int i = 0; i < k + 1; i++)
  {
    cout << ret[0][i] << "";
  }

  return 0;
}