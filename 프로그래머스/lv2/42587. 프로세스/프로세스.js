function solution(priorities, location) {
    const answer = []
    const origin = priorities.map((v,i) => {
        return [v,i]
    })
    // console.log(origin)
    
    let queue = origin.slice()
    
    for(let i=0;i<priorities.length;i++) {
    // Find the largest value at the first index in the queue array
    let largestValue = queue.reduce((max, current,i) => {
      return current[0] > max[0] ? [current[0],current[1],i] : max;
    }, [queue[0][0],queue[0][1],0]);
    
    // console.log(largestValue)
    answer.push(largestValue[1])
    queue = queue.slice(largestValue[2]+1).concat(queue.slice(0,largestValue[2]))
    // console.log(queue)
    
    }
    // console.log("A",answer)
    return answer.indexOf(location)+1
}