class Solution {
public:
   vector<int> finalPrices(vector<int>& prices) {
      vector<int> stack;
      for (int i = 0; i < prices.size(); i++) {
         while (!stack.empty() && prices[stack.back()] >= prices[i]) {
            prices[stack.back()] -= prices[i];
            stack.pop_back();
         }
         stack.push_back(i);
        }
      return prices;
    }
};
