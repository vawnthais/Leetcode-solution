class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        ans = 0
        heights.append(0)
        stack = []
        for i, h in enumerate(heights):
            while stack and heights[stack[-1]] > h:
                top = stack.pop()
                height = heights[top]
                width = i if not stack else i - stack[-1] -1
                ans = max(ans, height * width)
            stack.append(i)
        return ans