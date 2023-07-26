const solution = (phone) => {
    const arr = phone.slice().sort()
    
    for (let i=0;i<arr.length-1;i++) {
        if ( arr[i+1].indexOf(arr[i]) === 0 ) {
            return false
        }
    }
return true
}


// function solution(phone_book) {
//     for (let i=0 ; i<phone_book.length; i++) {
//        for (let j=i+1 ; j< parseInt(phone_book.length/2)+1; j++) {
//             if (phone_book[j].indexOf(phone_book[i])===0) return false
//         }
//     }
//     return true
// }

// const minLengthCount = (arr,minLength) => {
//     let i =0 
//     for (let s of arr) {
//         if (s.length=== minLength) i++
//     }
//     return i
// }