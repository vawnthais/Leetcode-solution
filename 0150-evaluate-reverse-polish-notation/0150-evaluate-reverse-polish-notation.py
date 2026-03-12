class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        ans = []
        num = 0
        if len(tokens) == 1:
            return int(tokens[0])
        for token in tokens:
            if not token in "+-*/":
                ans.append(int(token))
            else:
                string = f"{ans[-2]} {token} {ans[-1]}"
                num = int(eval(string))
                ans.pop()
                ans.pop()
                ans.append(num)
        return num