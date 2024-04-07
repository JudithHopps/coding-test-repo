#include <string>
#include <map>
#include <iostream>
using namespace std;
int need[] = { 1,1,2,2,2,8 },have,ret;
string s,str;
// 중복 체크해??
map<string, int > mp;
int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	mp["c="] = 0;
	mp["c-"] = 1;
	mp["dz="] = 2;
	mp["d-"] = 3;
	mp["lj"] = 4;
	mp["nj"] = 5;
	mp["s="] = 6;
	mp["z="] = 7;

	//str = "nljj"; // ljes = njak";
	cin >> str;
	for (auto it : mp) {
		while (str.find(it.first)!=string::npos) {
			int find = str.find(it.first);
			//cout << find << "\n";
			ret++;
			str = str.substr(0,find) +" " + str.substr(find+it.first.size());
			//cout << str << "\n";
		}
	}
	while (str.find(" ") != string::npos) {
		str.erase(str.find(" "),1);
	}
	ret += str.size();
	cout << ret << "\n";
	return 0;
}
