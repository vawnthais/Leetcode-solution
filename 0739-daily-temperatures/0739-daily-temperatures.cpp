class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> stack;
        vector<int> ans(temperatures.size(), 0);
        for ( int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.back()]) {
                int pre_id = stack.back();
                ans[pre_id] = i - pre_id;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return ans;
    }
};