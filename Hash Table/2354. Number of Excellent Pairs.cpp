class Solution {
public:
    int countBit1Fast(uint32_t n) {
        n = (n & 0x55555555u) + ((n >> 1) & 0x55555555u);
        n = (n & 0x33333333u) + ((n >> 2) & 0x33333333u);
        n = (n & 0x0f0f0f0fu) + ((n >> 4) & 0x0f0f0f0fu);
        n = (n & 0x00ff00ffu) + ((n >> 8) & 0x00ff00ffu);
        n = (n & 0x0000ffffu) + ((n >> 16) & 0x0000ffffu);
        return n;
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long result = 0;
        sort(nums.begin(), nums.end());        
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int N = nums.size();
        for (int i = 0; i < N; ++i)
            if (countBit1Fast(nums[i]) * 2 >= k)
                ++result;
        vector<long long> M(31);
        for (int x : nums)
        {
            int c = countBit1Fast(x);
            for (int a = 0; a < 31; ++a)
                if (a + c >= k)
                    result += 2 * M[a];
            ++M[c];
        }
        return result;
    }
};
