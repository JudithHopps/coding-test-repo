const input = Number(require('fs').readFileSync('/dev/stdin').toString().trim())

const answer = 'long '.repeat(input/4)+'int'
console.log(answer)