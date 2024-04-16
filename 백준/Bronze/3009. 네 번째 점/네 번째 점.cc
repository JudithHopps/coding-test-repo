#include <iostream>
#include <algorithm>
using namespace std;
int x[4],y[4],n,m;
int main()
{
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	n = x[0] ^ x[1] ^ x[2];
	m = y[0] ^ y[1] ^ y[2];
	cout << n << " " << m << "\n";
	return 0;
}
