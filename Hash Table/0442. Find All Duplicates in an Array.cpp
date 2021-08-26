class Solution {
public:
    vector<int> findDuplicates( vector<int>& nums ) {
        vector<int> result;
        int n = nums.size() + 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            int k = nums[i] % n - 1;
            while (k >= 0 && k < nums.size() && i != k)
                if (nums[i] % n != nums[k] % n)
                {
                    swap( nums[i], nums[k] );
                    k = abs(nums[i]) - 1;
                }
                else
                {
                    if (nums[k] < n)
                    {
                        result.push_back( nums[k] );
                        nums[k] += n;
                    }
                    break;
                }
        }
        return result;
    }
};