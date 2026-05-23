class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minimum = INT_MAX;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; i++) {
            int cur_min = arr[i+1] - arr[i];
            if (cur_min < minimum) {
                ans.clear();
                minimum = cur_min;
                ans.push_back({arr[i], arr[i+1]});
            }
            else if (cur_min == minimum) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};