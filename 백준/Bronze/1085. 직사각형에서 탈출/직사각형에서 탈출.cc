#include <iostream>
#include <algorithm>
using namespace std;
int x,y,w,h;
int main()
{
	cin >> x >> y >> w >> h;
	int ret = min(abs(x - 0), abs(w - x));
	ret = min(ret, abs(y - 0));
	ret = min(ret, abs(h - y));
	cout << ret << "\n";
	return 0;
}
