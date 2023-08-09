function solution(a, b, c, d) {
   const arr = [a,b,c,d]
   
   const map = new Map()
   for (let i=0 ; i<arr.length;i++){
       map.set(arr[i], (map.get(arr[i]) | 0) +1)
       
   }
    console.log(map)
    
    if (map.size ===1) return a*1111
    else if (map.size===4) return Math.min(...map.keys())
    else {
        const sortArr = [...map].sort((a,b)=>b[1] - a[1])
        console.log(sortArr)
        if (sortArr[0][1] ===3) {
            return Math.pow(10*sortArr[0][0] + sortArr[1][0],2)
        } else if (sortArr[0][1] === sortArr[1][1] ){
            return (sortArr[0][0]+sortArr[1][0]) * Math.abs(sortArr[0][0]-sortArr[1][0])
        } else {
            return sortArr[2][0]*sortArr[1][0]
        }
    }
}