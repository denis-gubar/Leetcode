class Solution {
public:
    int lateFee(vector<int>& daysLate) {
        int result = 0;
        for (int x : daysLate)
            if (x > 5)
                result += 3 * x;
            else if (x > 1)
                result += 2 * x;
            else
                ++result;
        return result;
    }
};
