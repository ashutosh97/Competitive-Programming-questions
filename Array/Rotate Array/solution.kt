internal class Solution {
  fun rotate(nums:IntArray, k:Int) {
    k = k % nums.size
    val count = 0
    val start = 0
    while (count < nums.size)
    {
      val current = start
      val prev = nums[start]
      do
      {
        val next = (current + k) % nums.size
        val temp = nums[next]
        nums[next] = prev
        prev = temp
        current = next
        count++
      }
      while (start != current)
      start++
    }
  }
}