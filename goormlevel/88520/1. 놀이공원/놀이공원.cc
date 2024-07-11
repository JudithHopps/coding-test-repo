
#include<iostream>
#include<algorithm>


using namespace std;
const int MX = 987654321;
int T,n,k,a[104][104],ret = MX; 

bool isOut(int y,int x){
	int ny = y+k-1; 
	int nx = x+k-1; 
	if(ny>=n||nx>=n) return true;
	return false; 
}
int go(int y,int x){
	if(isOut(y,x)) return MX; 
	
	int cnt = 0;
	int ey = y+k-1;
	int ex = x+k-1;
	for(int i=y;i<=ey;i++){
		for(int j=x;j<=ex;j++){
			cnt+= a[i][j];
		}
	}
	return cnt;
}
int main() {
	cin >> T; 

	
	while(T--){
		cin >> n >> k;
		ret = MX;
	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> a[i][j]; 
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ret = min(ret,go(i,j));
			}
		}
		cout << ret<<"\n";
	}
	return 0;
}