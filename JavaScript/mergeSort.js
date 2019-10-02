function merge (left, right) {
	let resultArray = [], leftIndex = 0, rightIndex = 0;
	while (leftIndex < left.length && rightIndex < right.length) {
	  if (left[leftIndex] < right[rightIndex]) {
		resultArray.push(left[leftIndex]);
		leftIndex++
	  } else {
		resultArray.push(right[rightIndex]);
		rightIndex++;
	  }
	}

	return resultArray
			.concat(left.slice(leftIndex))
			.concat(right.slice(rightIndex));
  }

  function mergeSort (unsortedArray) {
	if (unsortedArray.length <= 1)
	  return unsortedArray;
	const middle = parseInt(unsortedArray.length / 2);
	const left = unsortedArray.slice(0, middle);
	const right = unsortedArray.slice(middle);

	return merge(
	  mergeSort(left), mergeSort(right)
	);
  }


/*
 * Driver code
 */
let arr = [8, 9, 1, 8, 4, 7, 2];

console.log("Unsorted: ", arr);
arr = mergeSort(arr);
console.log("Sorted: ", arr);
