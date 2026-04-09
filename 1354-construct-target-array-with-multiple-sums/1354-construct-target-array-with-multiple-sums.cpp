class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) {
            if (target[0] == 1) return true;
            else return false;
        }

        long long totalSum = 0;
        priority_queue<int> pd;
        for (long long x : target) {
            totalSum += x;
            pd.push(x);
        }

        while (pd.top() != 1) {
            long long maxVal = pd.top();
            pd.pop();

            long long rest = totalSum - maxVal;
            if (rest == 1) return true;
            if (rest == 0 || rest >= maxVal) return false;

            long long preVal = maxVal % rest;

            if (preVal == 0) return false;
            totalSum = preVal + rest;
            pd.push(preVal);
        }
        return true;
    }
};
