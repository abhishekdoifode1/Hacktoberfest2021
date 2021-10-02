const arr = [24,10,32,,35,8,17,53,40,15,25];

function bubbleSort(arr) {
  for(let i = 0; i< arr.length - 1; i++) {
    for(let j = 0; j < arr.length - i - 1; j++) {
       if (arr[j] > arr[j+1])
        {
        swap(arr,j,j+1);
        }
    }
  }
}

function swap(arr, prev, next) {
    var temp = arr[prev];
    arr[prev] = arr[next];
    arr[next] = temp;
}

//unsorted array
console.log(arr);

bubbleSort(arr);

//sorted array
console.log(arr);
