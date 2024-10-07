class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        for (int k = 0; k < 30; ++k)
        {
            int count = 0;
            for (int x : nums)
                count += (x & (1 << k)) >> k;
            result += count * (N - count);
        }
        return result;
    }
};
