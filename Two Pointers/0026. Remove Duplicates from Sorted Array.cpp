class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int N = nums.size();
        int a = 1, b = 1;
        while(a < N)
        {
            if (nums[a] != nums[a - 1])
            {
                nums[b] = nums[a];
                ++b;
            }
            ++a;
        }
        return b;
    }
};