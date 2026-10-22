class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:

        st = SortedList()
        ans = []

        for i in range(len(nums)):
            st.add(nums[i])

            if len(st) > k:
                st.remove(nums[i - k])

            if len(st) == k:
                ans.append(st[-1])

        return ans