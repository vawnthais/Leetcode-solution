class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> prefix_odd;
        unordered_map<int, int> prefix_even;
        int sum_odd = 0;
        int sum_even = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                sum_even += nums[i];
                prefix_even[i] = sum_even;
            }
            else {
                sum_odd += nums[i];
                prefix_odd[i] = sum_odd;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                int left_even = prefix_even[i-2];
                int right_even = prefix_odd[n % 2 == 0 ? n - 1 : n -2 ] - prefix_odd[i -1];
                
                int left_odd = prefix_odd[i-1];
                int right_odd = prefix_even[n % 2 == 0 ? n - 2 : n -1] - prefix_even[i];

                if (left_even + right_even == left_odd + right_odd) ans++;
            }
            else {
                int left_even = prefix_even[i-1];
                int right_even = prefix_odd[n % 2 == 0 ? n - 1 : n -2 ] - prefix_odd[i];

                int left_odd = prefix_odd[i-2];
                int right_odd = prefix_even[n % 2 == 0 ? n - 2 : n -1] - prefix_even[i-1];

                if (left_even + right_even == left_odd + right_odd) ans++;
            }   
        }
        return ans;
    }
};