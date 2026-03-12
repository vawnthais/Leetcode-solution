class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if not token in "+-*/":
                stack.append(int(token))
            else:
                b = stack.pop()
                a = stack.pop()
                print(a, b)
                if token == '+':
                    stack.append(a + b)
                elif token == '-':
                    stack.append(a - b)
                elif token == '*':
                    stack.append(a * b)
                else:
                    stack.append(int(a / b))
        return stack[0]