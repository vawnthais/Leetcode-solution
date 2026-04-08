class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //heap sẽ chứa (tổng, i, j)
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pd(cmp);

        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return result;
        }
        int n1 = nums1.size();
        for (int i = 0; i < min(n1, k); i++) {
            pd.push({nums1[i] + nums2[0], i, 0});
        }
        while (k-- > 0  && !pd.empty()) {
            vector<int> top_heap = pd.top();
            pd.pop();

            int i = top_heap[1];
            int j = top_heap[2];

            result.push_back({nums1[i], nums2[j]});

            if ( j+1 < nums2.size()) {
                pd.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }
        return result;
    }
};