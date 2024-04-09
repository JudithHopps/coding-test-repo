
#include <iostream>
using namespace std;
int ret1, ret2,n,f[44];

int fibo(int n) {
	
	if (n <= 2) return 1;
	ret1++;
	return fibo(n - 1) + fibo(n - 2);
}
int fibo2(int n) {
	f[1] = f[2] = 1;

	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		ret2++;	
	}
	return f[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	fibo(n); fibo2(n);
	cout << ret1+1 <<" " << ret2 <<"\n";
	return 0;
}
