#include <string>
#include <iostream>
using namespace std;
int t, ret;
bool flag = false;
string str;
int main() {
	getline(cin,str);
	for (char c : str) {
		if (c != ' ' && !flag) {
			ret++;
			flag = true;
		}
		else if(c==' ') flag = false;
	}
	cout << ret << "\n";
	return 0;
}