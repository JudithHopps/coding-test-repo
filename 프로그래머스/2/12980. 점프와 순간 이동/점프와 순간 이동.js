function solution(n)
{
    // k칸 , 현재 거리 X 2
    // K 칸을 점프하면 K 만큼의 건전지 사용량이 듭니다.
    // 사용해야 하는 건전지 사용량의 최솟값을 return하는 solution 함수를 만들어 주세요.
    
    let ret = 0;
    while(n){
        ret += n % 2;
        n= parseInt(n / 2);
    }
    
    
    
    
    return ret;
}