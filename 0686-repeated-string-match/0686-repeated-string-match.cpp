class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string check = "";
        while (check.size() < b.size()) {
            check += a;
        }
        if (check.find(b) != string::npos) {
            return check.size() / a.size();
        }
        check += a;
        if (check.find(b) != string::npos) {
            return check.size() / a.size();
        }
        return -1;
    }
};