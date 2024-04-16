#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n, sum;


int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	while (1) {
		cin >> n;
		if (n == -1) break;
		sum = 0;
		v.clear();

		for (int i = 1; i < n; i++) {
			if (n%i == 0) {
				v.push_back(i);
				sum += i;
			}
		}

		if (sum == n) {
			cout << n << " = ";
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
				if (i != v.size() - 1) {
					cout << " + ";
				}
			}
		}
		else {
			cout << n << " is NOT perfect.";
		}
		cout << "\n";

	}
	return 0;
}
