
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        for i in range(len(flowerbed)):
            if i == len(flowerbed) - 1:
                if flowerbed[i] == flowerbed[i-1] == 0:
                    n -= 1
                    flowerbed[i] = 1
            elif i == 0 and flowerbed[i] == flowerbed[i+1] == 0:
                n -= 1
                flowerbed[i] = 1
            elif flowerbed[i-1] == flowerbed[i] == flowerbed[i+1] == 0:
                n-=1
                flowerbed[i] = 1
            if n <= 0:
                return True
        return n <= 0
