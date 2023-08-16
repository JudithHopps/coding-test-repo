const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map(Number)
let str = ''
const arr = ['+','-','*','/','%']
for (const s of arr) {
    str += parseInt(eval(input[0] + s + input[1])) + '\n'
}
console.log(str)