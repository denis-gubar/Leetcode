class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);
        int result = 0, current = 0;
        for(int n: nums)
            if (n == 1)
                ++current;
            else
            {
                result = max(result, current);
                current = 0;
            }
        return result;
    }
};