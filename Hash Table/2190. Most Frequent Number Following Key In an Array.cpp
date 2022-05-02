class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int result = -1;
        int best = -1;
        int N = nums.size();
        vector<int> M(1'001);
        for (int i = 0; i <= N - 2; ++i)
            if (nums[i] == key)
            {
                int target = nums[i + 1];
                ++M[target];
            }
        for (int target = 1; target <= 1'000; ++target)
            if (M[target] > best)
            {
                best = M[target];
                result = target;
            }
        return result;
    }
};
