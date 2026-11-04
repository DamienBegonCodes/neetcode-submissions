class Solution:
    closing = {
        ')' : '(',
        ']' : '[',
        '}' : '{'
    }
    def isValid(self, s: str) -> bool:
        stack = []
        for ch in s:
            if ch not in self.closing:
                stack.append(ch)
            elif bool(stack) and self.closing[ch] == stack[-1]:
                stack.pop()
            else:
                return False
        return not bool(stack)