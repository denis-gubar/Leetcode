class Solution {
public:
    int removeDuplicates( vector<int>& nums ) {
        int result = nums.size(), duplicates = 0;
        if (result > 2)
        {
            for (int i = 1; i + 1 < nums.size(); ++i)
                if (nums[i - 1] == nums[i + 1])
                {
                    --result; ++duplicates;
                }
                else
                    nums[i - duplicates] = nums[i];
            nums[result - 1] = nums[nums.size() - 1];
        }
        return result;
    }
};