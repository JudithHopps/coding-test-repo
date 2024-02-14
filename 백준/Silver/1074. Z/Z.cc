#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, c;
    cin >> n >> r >> c;

    int size = 1 << n;
    int result = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int quadrant = 0;
        int shift = 1 << i;
        if (r >= shift)
        {
            quadrant += 2;
            r -= shift;
        }
        if (c >= shift)
        {
            quadrant += 1;
            c -= shift;
        }
        result += quadrant * shift * shift;
    }

    cout << result << "\n";

    return 0;
}
