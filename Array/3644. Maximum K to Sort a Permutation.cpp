class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int const N = nums.size();
        int const INF = (1 << 20) - 1;
        int result = INF;
        for (int i = 0; i < N; ++i)
            if (nums[i] != i)
                result &= nums[i];
        if (result == INF)
            result = 0;
        return result;
    }
};
