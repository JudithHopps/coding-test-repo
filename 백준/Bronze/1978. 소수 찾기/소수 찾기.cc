#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;
int a[1004];
int n, m,cnt;

void era() {
	memset(a, 1, sizeof(a));
	a[0] = 0; a[1] = 0;

	for (int i = 2; i <= 1004; i++) {
		for (int j = i * 2; j <= 1004; j += i) {
			
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

	cin >> n;
	while (n--) {
		cin >> m;
		if (a[m]) cnt++;
	}

	cout << cnt << "\n";
	return 0;
}
