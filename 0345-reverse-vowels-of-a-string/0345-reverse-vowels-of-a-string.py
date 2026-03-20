class Solution:
    def reverseVowels(self, s: str) -> str:
        arr = list(s)
        i = 0
        j = len(arr) -1
        while i < j:
            if arr[i].lower() in "aeiou":
                if arr[j].lower() in "aeiou":
                    arr[i], arr[j] = arr[j], arr[i]
                    i += 1
                    j -= 1
                else:
                    j -= 1
            else:
                i += 1    
        return "".join(arr)  
        