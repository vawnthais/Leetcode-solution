class Solution {
public:
   vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      vector<bool> ans;
      int max_candies = 0;
      for (int x : candies) {
         if (x > max_candies) {
            max_candies = x;
         }
      }

      for (int i = 0; i < candies.size(); i++) {
         if (candies[i] + extraCandies >= max_candies) {
            ans.push_back(true);
         } else {
            ans.push_back(false);
         }
      } 
      return ans;
   }
};