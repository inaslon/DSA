class Solution:
    def isMonotonic(self, nums: list[int]) -> bool:
        n = len(nums)
        incr = True
        decr = True

        for i in range(1,n):
            if nums[i-1]<nums[i]:
                decr = False
            if nums[i-1]>nums[i] :
                incr = False

        return decr or incr