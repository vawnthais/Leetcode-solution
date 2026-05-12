class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for (int x : nums) {
            sum = (sum + x) % p;
       }
        if (sum == 0) return 0;
        unordered_map<int, int> prefix_mod;
        prefix_mod[0] = -1;
        int min_len = nums.size();
        int cur_mod = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_mod = (cur_mod + nums[i]) % p;
            int target_mod = (cur_mod - sum + p) % p;
            if (prefix_mod.find(target_mod) != prefix_mod.end()) {
                min_len = min(min_len, i - prefix_mod[target_mod]);
            }
            prefix_mod[cur_mod] = i;
        }
        return min_len == nums.size() ? -1 : min_len;
    }
};