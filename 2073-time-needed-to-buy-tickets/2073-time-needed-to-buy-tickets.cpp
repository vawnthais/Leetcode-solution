class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        int i = 0;
        while (tickets[k] != 0) {
            if (tickets[i] != 0) {
                tickets[i]--;
                count++;
                i++;
            } else i++;
            if (i == tickets.size()) i = 0;
        }
        return count;
    }
};