class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int result = 0;        
        while (!is_sorted(nums.begin(), nums.end()))
        {
            int const N = nums.size();
            int best = nums[0] + nums[1];
            int current = 0;
            for (int i = 2; i < N; ++i)
                if (best > nums[i - 1] + nums[i])
                    best = nums[i - 1] + nums[i], current = i - 1;
            nums[current] += nums[current + 1];
            nums.erase(nums.begin() + current + 1);
            ++result;
        }
        return result;
    }
};
