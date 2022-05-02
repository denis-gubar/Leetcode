class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int result = 0;
        int N = nums.size();
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (nums[i] == nums[j] && i * j % k == 0)
                    ++result;
        return result;
    }
};
