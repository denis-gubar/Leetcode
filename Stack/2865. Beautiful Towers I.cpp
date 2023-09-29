class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int N = maxHeights.size();
        long long result = 0;
        for (int i = 0; i < N; ++i)
        {
            long long current = maxHeights[i];
            int x = maxHeights[i];
            for (int j = i - 1; j >= 0; --j)
            {
                x = min(x, maxHeights[j]);
                current += x;
            }
            x = maxHeights[i];
            for (int j = i + 1; j < N; ++j)
            {
                x = min(x, maxHeights[j]);
                current += x;
            }
            result = max(result, current);
        }
        return result;
    }
};
