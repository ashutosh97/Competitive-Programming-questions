const myArray = [2, 4, 1, 6, -7, 8, 5, 9, 3, 4];

const quickSortV1 = arr => {
  if (arr.length <= 1) {
    return arr;
  }

  // shift takes out the element of the array
  // so that it can reach the base case
  let pivot = arr.shift();
  let left = arr.filter(el => el < pivot);
  let right = arr.filter(el => el >= pivot);

  let leftSorted = quickSortV1(left);
  let rightSorted = quickSortV1(right);

  return [...leftSorted, pivot, ...rightSorted];

};

console.log(quickSortV1(myArray));