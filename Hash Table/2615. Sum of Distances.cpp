class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int const N = nums.size();
        vector<long long> result(N);
        vector<int> next(N);
        unordered_map<int, int> M;
        for (int i = N - 1; i >= 0; --i)
            next[i] = M[nums[i]], M[nums[i]] = i + 1;
        for(int i = 0; i < N; ++i)
            if (next[i] > 0)
            {
                int count = 0;
                for (int j = i, p; j >= 0; )
                    ++count, result[i] += j - i, j = next[j] - 1;
                long long total = result[i];
                int left = 0;
                for (int j = next[i] - 1, prev = i, p; j >= 0; )
                {
                    ++left, --count, total += 1LL * (left - count) * (j - prev), result[j] = total;
                    prev = j, p = next[j] - 1, next[j] = 0, j = p;
                }
            }
        return result;
    }
};
