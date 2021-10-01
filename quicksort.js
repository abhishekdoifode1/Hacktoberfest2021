// CODE : A javascript Arrow function to demonstrate quicksort
const quickSort = (nums) => {
	let pivot = nums[0];                                                    // Pivot is the 0th element
	return nums.length                                                      // If length of array is 0 return the empty array itself
		? [
				...quickSort([...nums.slice(1).filter((c) => c <= pivot)]), // Store items <= pivot in this array
				pivot,                                                      // Then store the pivot element
				...quickSort([...nums.slice(1).filter((c) => c > pivot)]),  // Store items >= pivot in this array
		  ]                                                                 // Finally unpacking the array items in a new array
		: nums;                                                             
};

console.log(quickSort([1, 2, 1, 12, 1, 1, 3, 1, 2, 7, 9, 2, 4, 1, 4, 9]));
console.log(quickSort([99, 55, -9, 88, 93, 22, 11, -12, 0, 1, 99, 45, 67]));
