class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        ans = [0] * n
        
        for i in range(n):
            for j in range(i+1, n):
                if prices[j] <= prices[i]:
                    ans[i] = prices[i] - prices[j]
                    break
            else:
                ans[i] = prices[i]
        return ans