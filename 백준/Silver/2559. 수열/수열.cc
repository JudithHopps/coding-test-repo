#include <bits/stdc++.h>
using namespace std;
int a[100004], n, k, res = -10000000, psum[100004];

// 최댓값 -> 최솟값부터 최대값.

// 틀린 이유 : 최댓값이 0 이하일 수도 있다.
// 최솟값을 가장 작은 값으로 갱신. 


int main()
{
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    psum[i] = psum[i - 1] + a[i];

    if (i >= k)
    {
      // cout << "T"
      //      << "\n";
      if ((psum[i] - psum[i - k]) > res)
      {
        res = psum[i] - psum[i - k];
        // cout << res << "\n";
      }
    }

    // cout << "a[i]: " << a[i] << "psum[i]: " << psum[i] << "\n";
  }

  cout << res << "\n";

  return 0;
}
