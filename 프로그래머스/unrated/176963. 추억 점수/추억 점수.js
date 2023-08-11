function solution(name, yearning, photo) {
    const map = new Map()
    name.map((v,i) => {
        map.set(v,yearning[i])
    })
    console.log(map)
    
    const answer = []
    for (const arr of photo) {
        let sum = 0
        arr.forEach((v) =>{
            sum+=map.get(v) || 0
            // console.log(arr, v,sum)
        })
        answer.push(sum)      
    }
    return answer
}