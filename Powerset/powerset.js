// given an array, provide all subsets (powersets);

// [1,3,2]
// => [[],[1],[2],[3],[1,3],[1,2][2,3],[1,2,3]]

const powerSet = (arr) => {
  const result = [];

  const _recurse = (chosen, remaining) => {
    if (remaining.length === 0) {
      result.push(chosen);
    } else {
      _recurse(chosen, remaining.slice(1));
      _recurse(chosen.concat(remaining[0]), remaining.slice(1));
    }
  };

  _recurse([], arr);
  return result;
}

console.log(powerSet([1, 2, 3]));