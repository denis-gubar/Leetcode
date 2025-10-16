class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        int N = nums.size();
        int result = N;
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        unordered_map<int, int> A;
        for (auto [key, value] : M)
            ++A[value];
        int maxGroupSize = 0;
        int minGroupSize = N;
        for (auto [key, value] : A)
        {
            maxGroupSize = max(maxGroupSize, key);
            minGroupSize = min(minGroupSize, key);
        }
        maxGroupSize = min(maxGroupSize, minGroupSize + 1);
        for (int groupSize = 2; groupSize <= maxGroupSize; ++groupSize)
        {
            int count = 0;
            for (auto [key, value] : A)
            {
                int a = key / (groupSize - 1);
                int b = key / groupSize;
                if (key % groupSize == 0)
                {
                    count += value * b;
                    continue;
                }
                if (a > b)
                {
                    count += value * (b + 1);
                    continue;
                }
                count = N;
                break;
            }
            result = min(result, count);
        }
        return result;
    }
};
