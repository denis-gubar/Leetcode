class Solution {
public:
    int bitcount(int x)
    {
        int result = 0;
        while (x > 0)
        {
            x &= x - 1;
            ++result;
        }
        return result;
    }
    bool canSortArray(vector<int>& nums) {
        int N = nums.size();
        for (int i = 1; i < N; ++i)
        {
            int j = i;
            while (j > 0)
                if (nums[j - 1] > nums[j] && bitcount(nums[j - 1]) == bitcount(nums[j]))
                {
                    swap(nums[j - 1], nums[j]);
                    --j;
                }
                else
                    break;
        }
        return is_sorted(nums.begin(), nums.end());
    }
};
