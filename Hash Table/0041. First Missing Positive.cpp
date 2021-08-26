class Solution {
public:
    int firstMissingPositive( vector<int>& nums ) {
        for (int i = 0; i < nums.size(); ++i)
        {
            long long k = nums[i] - 1LL;
            while (k >= 0 && k < nums.size() && i != k && nums[i] != nums[k])
            {
                swap( nums[i], nums[k] );
                k = nums[i] - 1LL;
            }
        }
        for (int i = 0; i < nums.size(); ++i)
            if (i != nums[i] - 1LL)
                return i + 1;
        return nums.size() + 1;
    }
};