class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (long long x : nums) {
            sum = (sum + x);
       }
        if (sum % p== 0) return 0;
        unordered_map<int, int> prefix_mod;
        prefix_mod[0] = -1;
        int min_len = nums.size();
        long long cur_mod = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_mod = (cur_mod + nums[i]) % p;
            long long target_mod = (cur_mod - sum % p + p) % p;
            if (prefix_mod.count(target_mod)) {
                min_len = min(min_len, i - prefix_mod[target_mod]);
            }
            prefix_mod[cur_mod] = i;
        }
        return min_len == nums.size() ? -1 : min_len;
    }
};
