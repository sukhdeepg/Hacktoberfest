const insertionSort = (nums) => {
  checkLoopInvariant(nums, input, 0)
  for (let i = 1; i < nums.length; i++) {
    ...
    checkLoopInvariant(nums, input, i)
    while (j >= 0 && nums[j] > tmp) {
      ...
    }
    nums[j+1] = tmp
  }
  checkLoopInvariant(nums, input, nums.length)
  return nums
}
