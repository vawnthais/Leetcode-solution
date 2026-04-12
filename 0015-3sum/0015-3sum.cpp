class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0  && nums[i] == nums[i-1]) continue;

            int x = nums[i];
            int ind_left = i + 1;
            int ind_right = nums.size() - 1;

            while (ind_left < ind_right) {
                int sum = nums[i] + nums[ind_left] + nums[ind_right];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[ind_left], nums[ind_right]});

                    while (ind_left < ind_right && nums[ind_left] == nums[ind_left + 1]) ind_left++;
                    while (ind_right > ind_left && nums[ind_right] == nums[ind_right - 1]) ind_right--;
                    ind_left++;
                    ind_right--;
                }
                else if (sum < 0) {
                    ind_left++;
                }
                else {
                    ind_right--;
                }
            }
        }
        return ans;
    }
};