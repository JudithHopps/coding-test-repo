function solution(numbers) {
    const result = new Array(numbers.length).fill(-1); // Initialize the result array with -1s.
    const stack = []; // Stack to store indices of elements.

    for (let i = 0; i < numbers.length; i++) {
        while (stack.length > 0 && numbers[i] > numbers[stack[stack.length - 1]]) {
            result[stack.pop()] = numbers[i]; // Assign the greater number to the indices in the stack.
        }
        stack.push(i); // Push the current index onto the stack.
    }

    return result;
}
