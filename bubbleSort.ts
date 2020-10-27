function bubbleSort(arr: number[]): void {
    let swapped = true;
    for (let i=0; i<arr.length-1 && swapped; i++) {
        swapped = false;
        for (let j=0; j<arr.length-1; j++) {
            if (arr[j] > arr[j+1]) {
                [arr[j], arr[j+1]] = [arr[j+1], arr[j]];
                swapped = true;
            }
        }
    }
}

let N = 10;
let arr = Array.from(Array(N)).map(() => Math.floor(Math.random() * 100));
console.log(`before: ${arr.join(', ')}`);
bubbleSort(arr);
console.log(`after : ${arr.join(', ')}`);
