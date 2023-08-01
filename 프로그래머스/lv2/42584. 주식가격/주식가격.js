function solution(prices) {
    const answer = []
   
    
    for (let i=0;i<prices.length;i++) {
        let cur = prices[i] // 현재 가격
        let j = i+1 // 비교 가격
        let temp = 0 // 기간
         
        while (j<prices.length+1) {
            if(cur <= prices[j]) {
                temp++
                j++
                continue;
            }
            else if (temp==0 && cur > prices[j]) {
                answer.push(1)
                break;
            }
            // 마지막 인덱스
            else if (temp==0 && j===prices.length) {
               
                answer.push(0)
                break;
            }
            answer.push(temp)
            temp = 0
            break;

            // 
        }
        
        
    }
    
    return answer
    
}