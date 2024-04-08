#include <iostream>
using namespace std;
int n=9, m=9, a[104][104],mx,y,x;


void input(int arr[][104]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (mx <= arr[i][j]) {
				mx = arr[i][j];
				y = i, x = j;
			}
		}
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input(a);

	cout << mx << "\n" << y+1 << " " << x+1 << "\n";


	return 0;
}
