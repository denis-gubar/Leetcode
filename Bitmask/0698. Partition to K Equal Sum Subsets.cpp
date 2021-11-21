class Solution {
public:
    bool calc(vector<unordered_set<int>> const& goodMasks, int N, int k, int i, int mask)
    {
        if (i == k)
            return true;
        for(int pos = 0; pos < N; ++pos)
            if ((mask & (1 << pos)) == 0)
            {
                for(int currentGroupMask : goodMasks[pos])
                    if ((currentGroupMask & mask) == 0 && calc(goodMasks, N, k, i + 1, mask | currentGroupMask))
                        return true;
                break;
            }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int N = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (N < k || total % k != 0)
            return false;
        if (N == 1)
            return true;
        vector<unordered_set<int>> goodMasks(N);
        for(int mask = 1; mask < (1 << N); ++mask)
        {
            int sum = 0;
            int firstBit = N;
            for(int z = 0; z < N; ++z)
                if (mask & (1 << z))
                {
                    sum += nums[z];                    
                    firstBit = min(firstBit, z);
                }
            if (sum * k == total)
                goodMasks[firstBit].insert(mask);
        }        
        return calc(goodMasks, N, k, 0, 0);
    }
};