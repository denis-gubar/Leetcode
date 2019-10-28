class Solution {
public:
    int firstMissingPositive( vector<int>& nums ) {
        for (int i = 0; i < nums.size(); ++i)
        {
            int k = nums[i] - 1;
            while (k >= 0 && k < nums.size() && i != k && nums[i] != nums[k])
            {
                swap( nums[i], nums[k] );
                k = nums[i] - 1;
            }
        }
        for (int i = 0; i < nums.size(); ++i)
            if (i != nums[i] - 1)
                return i + 1;
        return nums.size() + 1;
    }
};