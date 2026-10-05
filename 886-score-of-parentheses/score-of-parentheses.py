class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        firstclose = False;
        ans = 0
        open = 0

        for c in s:
            if c == '(':
                open = open + 1
                firstclose = False
            elif c == ')' and firstclose == False:
                ans += 2**(open-1)
                open = open - 1
                firstclose = True
            else :
                open = open -1

        return ans;                

        