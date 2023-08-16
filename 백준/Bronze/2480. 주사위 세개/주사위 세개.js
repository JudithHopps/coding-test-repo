const input = require('fs').readFileSync('/dev/stdin').toString().split(' ').map(Number)

const [a,b,c] = input.sort((a,b)=>b-a)

if (a===b && a === c) {
    console.log(10000 + a*1000)
} else if (a===b) {
    console.log(1000+ a*100)
} else if (b===c) {
    console.log(1000+ b*100)
} else {
    console.log(a*100)
}