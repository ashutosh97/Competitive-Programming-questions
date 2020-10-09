Write a function that counts how many different ways you can make change for an amount of money, given an array of coin denominations. For example, there are 3 ways to give change for 4 if you have coins with denomination 1 and 2:

1+1+1+1, 1+1+2, 2+2.
The order of coins does not matter:

1+1+2 == 2+1+1
Also, assume that you have an infinite amount of coins.

Your function should take an amount to change and an array of unique denominations for the coins:

  countChange(4, [1,2]) // => 3
  countChange(10, [5,2,3]) // => 4
  countChange(11, [5,7]) //  => 0