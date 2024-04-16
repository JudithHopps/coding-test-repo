#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
int n, m;


int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		if (m%n == 0) {
			cout << "factor" << "\n";
		}
		else if (n %m == 0) {
			cout << "multiple\n";
		}
		else {
			cout << "neither\n";
		}
	}
	return 0;
}
