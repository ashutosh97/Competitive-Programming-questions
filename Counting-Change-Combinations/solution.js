let countChange = function(money, coins) {
  if (coins.length === 0) {
      return 0;
  }

  coins = coins.slice(0).sort();
  let result = 0,
      largestCoin = coins.pop(),
      maxCount = 0;
  let maxRemain = money % largestCoin;

  if (maxRemain === 0) {
      result++;
      maxCount = money / largestCoin - 1;
  } else {
      maxCount = (money - maxRemain) / largestCoin;
  }

  for (let i = maxCount; i >= 0; i--) {
      result += countChange(money - largestCoin * i, coins);
  }

  return result;
}