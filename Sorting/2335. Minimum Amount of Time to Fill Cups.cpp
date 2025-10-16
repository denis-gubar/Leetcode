class Solution {
public:
    int fillCups(vector<int>& amount) {
        int result = 0;
        while (accumulate(amount.begin(), amount.end(), 0) > 0)
        {
            sort(amount.begin(), amount.end());
            --amount[2], ++result;
            if (amount[1] > 0)
                --amount[1];
        }
        return result;
    }
};
