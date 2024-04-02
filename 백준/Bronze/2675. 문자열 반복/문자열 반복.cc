#include <string>
#include <iostream>
using namespace std;
int t,n;
string str;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> str;
        for(char c : str){
            for(int i=0;i<n;i++){
                cout << c;
            }
        }
        cout <<"\n";
        
    }
    return 0;
}