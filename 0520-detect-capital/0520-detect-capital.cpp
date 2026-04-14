
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool check_all_upper = true;
        bool check_all_lower = true;
        bool check_title_case = true;
        for (int i = 0; i < word.size(); i++) {
            if (isupper(word[i])) {
                check_all_lower = false;
                if (i > 0) check_title_case = false;
            } else {
                check_all_upper = false;
            }
        }
        return check_all_upper || check_all_lower || check_title_case;
    }
};