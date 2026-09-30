class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        n = len(seq)
        a = [0]*n
        cnt = 0

        for i in range(n):
            if seq[i] == '(':
                cnt = cnt + 1
                a[i] = cnt % 2
            else: 
                a[i] = cnt % 2
                cnt = cnt - 1
            i = i+1
        return a          


        