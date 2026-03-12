class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans = []
        count = 0
        for i in range(1, n+1):
            if i in target:
                ans.append("Push")
                count += 1
            else:
                ans.append("Push")
                ans.append("Pop")
            if count == len(target):
                break
        return ans
        