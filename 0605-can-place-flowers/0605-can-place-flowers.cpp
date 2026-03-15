class Solution {
public:
   bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int count = 0, prev = 0;
      for (int x : flowerbed) {
         if (x == 1) {
            if (prev == 1) {
               count--;
            }
            prev = 1;
         } else {
            if (prev == 1) {
               prev = 0;
            } else {
               count++;
               prev = 1;
            }
         }
      }
      return count >= n; 
   }
};