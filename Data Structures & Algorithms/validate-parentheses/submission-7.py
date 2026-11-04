class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        closing = {
        ')' : '(',
        ']' : '[',
        '}' : '{'
        }
        for ch in s:
            if ch not in closing:
                stack.append(ch)
            elif stack and closing[ch] == stack[-1]:
                stack.pop()
            else:
                return False
        return True if not stack else False