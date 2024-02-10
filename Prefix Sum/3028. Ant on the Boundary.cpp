class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int result = 0;
        int balance = 0;
        for (int x : nums)
        {
            balance += x;
            result += balance == 0;
        }
        return result;
    }
};
