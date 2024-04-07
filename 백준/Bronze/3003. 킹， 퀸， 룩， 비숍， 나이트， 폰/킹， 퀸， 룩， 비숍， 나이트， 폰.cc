
#include <iostream>
using namespace std;
int need[] = { 1,1,2,2,2,8 },have;

int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 6; i++) {
		cin >> have;
		cout << need[i] - have << " ";
	}

	return 0;
}
