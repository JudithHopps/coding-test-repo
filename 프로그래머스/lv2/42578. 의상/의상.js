function solution(clothes) {
    const map = new Map()
    clothes.forEach(v=>{
        map.set(v[1], map.get(v[1]) +1 || 1)
    })
    
    console.log(map)
    console.log(map.forEach(v=>v))
    let count = 1 
    function logMapElements(value, key, map) {
        // console.log(`map.get('${key}') = ${value}`);
        count *= value+1
    }
    map.forEach(logMapElements);
    return count -1
}