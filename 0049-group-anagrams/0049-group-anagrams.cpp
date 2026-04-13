class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anastring;

        for (string x : strs) {
            string key = x;
            sort(key.begin(), key.end());
            anastring[key].push_back(x);
        }
        for (auto it = anastring.begin(); it != anastring.end(); ++it) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
