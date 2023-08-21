#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
  while (scanf("%d", &n) != EOF)
  {
    int cnt = 1, a = 1;
    while (true)
    {

      if (a % n == 0)
      {
        cout << cnt << "\n";
        break;
      }
      else
      {
        cnt++;
        a = (a * 10) + 1;
        a %= n;
      }
    }
  }
}