let array = [50, -14, 2, 39, 23, 0, 17];

/**
 * param: arr of type array
 * return: array
 * time complexity of O(n*n)
 */
let selectionSort = (arr) => {
  let len = arr.length;

  for (let i = 0; i < len; i++) {
    // set first element to min
    let min = i;

    // find the smallest number from subarray
    for (let j = i + 1; j < len; j++) {
      if (arr[min] > arr[j]) {
        min = j;
      }
    }

    // if position changes then swap the number
    if (min !== i) {
      let tmp = arr[i];
      arr[i] = arr[min];
      arr[min] = tmp;
    }
  }
  return arr;
};

console.log(selectionSort(array));
