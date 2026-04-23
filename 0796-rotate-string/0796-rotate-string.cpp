class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        string str = s + s;
        return str.find(goal) != string::npos;
    }
};