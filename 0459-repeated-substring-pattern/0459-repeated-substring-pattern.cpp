class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      string str = s + s;
      string sub = str.substr(1, str.size() - 2);
      return sub.find(s) != string::npos;
    }
};