class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int result = 0;
        for (int x : nums)
        {
            result += x;
            while (x > 0)
            {
                result -= x % 10;
                x /= 10;
            }
        }
        return result;
    }
};
