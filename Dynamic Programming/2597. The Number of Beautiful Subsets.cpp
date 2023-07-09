class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int K) {
        int N = nums.size();
        int result = 0;
        vector<int> bad;
        for (int i = 1; i < N; ++i)
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] + K == nums[j] || nums[i] - K == nums[j])
                    bad.push_back((1 << i) | (1 << j));
            }
        for (int mask = 1; mask < (1 << N); ++mask)
        {
            bool isGood = true;
            for (int x : bad)
                if ((mask & x) == x)
                {
                    isGood = false;
                    break;
                }
            result += isGood;
        }
        return result;
    }
};
