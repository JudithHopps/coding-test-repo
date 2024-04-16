#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;
int a[10004];
int n, m,sum,mn=-1;

void era() {
	memset(a, 1, sizeof(a));

	a[0] = 0, a[1] = 0;

	for (int i = 2; i <= 10004; i++) {
		if (a[i] == 0) continue;
		for (int j = i * 2; j <= 10004; j += i) {
			a[j] = 0;
		}
	}
}
int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	era();

	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		if (a[i] == 0) continue;	
		if (mn == -1) {
			mn = i;
		}
		sum += i;
		
	}
	if (sum) cout << sum << "\n";
	cout << mn << "\n";

	return 0;
}
