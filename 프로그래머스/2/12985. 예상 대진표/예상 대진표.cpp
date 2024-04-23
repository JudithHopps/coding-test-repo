#include <iostream>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    if(a>b) swap(a,b);
    
    
   
    while(!(a+1==b && a/2 +1 == b/2)){
        answer++;
        a = a/2 +(a%2 ? 1 : 0 );
        b = b/2 +(b%2 ? 1 : 0 );   
         cout << a <<" " << b <<"\n";
    }

    return answer+1;
}