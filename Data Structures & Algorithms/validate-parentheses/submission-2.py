class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for ch in s:
            if ch == '(' or ch == '[' or ch == '{': # if opening bracket
                stack.append(ch)
            else:
                if len(stack) == 0:
                    return False
                else:
                    top = stack.pop()

                    if (top == '(' and ch != ')') or (top == '[' and ch != ']') or (top == '{' and ch != '}'):
                        return False

        return not len(stack)
        