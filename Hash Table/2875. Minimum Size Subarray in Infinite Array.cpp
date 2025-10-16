class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int N = nums.size();
        int result = 0;
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        if (target % total == 0)
            return target / total * N;
        result += (target / total) * N;
        target %= total;
        long long A = 0;
        int current = 2 * N + 1;
        unordered_map<long long, int> M;
        for (int i = 0; i < 2 * N - 1; ++i)
        {
            A += nums[i % N];
            if (auto it = M.find(A - target); it != M.end())
                current = min(current, i - it->second);
            M[A] = i;
        }
        if (current > 2 * N)
            return -1;
        result += current;
        return result;
    }
};
