#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;
int n;
bool a[10000004];

void era() {
	memset(a, 1, sizeof(a));
	a[0] = a[1] = false;

	for (int i = 2; i <= n; i++) {
		if (a[i]==false) continue;
		for (int j = i * 2; j <= n; j += i) {
			a[j] = false;
		}
	}
}
int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	cin >> n;
	if (n == 1) return 0;

	for (int i = 2; i <= n; i++) {
		
		while (n%i == 0) {
			cout << i << "\n";
			n /= i;
		}
	}
	return 0;
}
