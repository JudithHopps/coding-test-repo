function solution(s) {
    const arr = s.split(' ').map(v => v.length> 1 ? v[0].toUpperCase() + v.slice(1).toLowerCase():v.toUpperCase())
    return arr.join(' ')
}