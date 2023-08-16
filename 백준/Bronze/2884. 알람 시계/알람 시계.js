const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map(Number);

let [hh, mm] = input;

mm = mm - 45;
if (mm < 0) {
    mm += 60;
    hh = hh === 0 ? 23 : hh - 1;
}

console.log(hh + ' ' + mm);
