class Solution:
    def maxDepth(self, s: str) -> int:
        st = []
        ans = 0
        for c in s:
            if c == "(":
                st.append("(")
            ans = max(ans,len(st))
            if c == ")":
                st.pop()

        return ans            
        