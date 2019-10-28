class Solution {
public:
    vector<int> findDisappearedNumbers( vector<int>& nums ) {
        vector<int> result;
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
                result.push_back(i + 1);
        return result;
    }
};