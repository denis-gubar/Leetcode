class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int result = 0;
        int N = nums.size();
        int stateCount = 1 << (2 * numSlots);
        vector<vector<int>> F(N + 1, vector<int>(stateCount));
        for (int i = 0; i < N; ++i)
        {
            for (int mask = 0; mask < stateCount; ++mask)
                if (F[i][mask] > 0 || mask == 0)
                    for (int slot = 0; slot < numSlots; ++slot)
                        if ((mask & (1 << slot)) == 0)
                        {
                            int nextMask = mask | (1 << slot);
                            F[i + 1][nextMask] = max(F[i + 1][nextMask], F[i][mask] + (nums[i] & (slot + 1)));
                        }
                        else if ((mask & (1 << (slot + numSlots))) == 0)
                        {
                            int nextMask = mask | (1 << (slot + numSlots));
                            F[i + 1][nextMask] = max(F[i + 1][nextMask], F[i][mask] + (nums[i] & (slot + 1)));
                        }
        }
        return *max_element(F[N].begin(), F[N].end());
    }
};
