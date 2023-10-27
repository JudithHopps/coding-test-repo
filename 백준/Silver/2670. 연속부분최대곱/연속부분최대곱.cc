#include <bits/stdc++.h>
using namespace std;
int n;
double a[10004], temp, ret;

int main()
{

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++)
  {
    if (temp * a[i] < a[i])
    {
      temp = a[i];
    }
    else
    {
      temp *= a[i];
    }
    ret = max(ret, temp);
  }
  printf("%.3lf", ret);

  return 0;
}