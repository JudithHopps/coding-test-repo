function solution(numbers) {
    const test = numbers.map(v=>v.toString()).sort()
    console.log(test)
    let arr = numbers.map(v=>v.toString())
                    .sort((a,b)=>(b+a) - (a+b))    
    if(arr[0]==='0') return '0'
    return arr.join('')
    
    
}