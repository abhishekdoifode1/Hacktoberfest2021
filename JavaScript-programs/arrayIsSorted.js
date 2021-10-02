function arrayIsSorted(arr){
  return +arr == +arr.sort()
}

console.log(arrayIsSorted([1, 2, 3]))
