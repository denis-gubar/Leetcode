class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int N = maxHeights.size();
        long long result = 0;
        vector<pair<int, int>> P(N);
        for (int i = 0; i < N; ++i)
            P[i] = { -maxHeights[i], i };
        sort(P.begin(), P.end());
        vector<int> A;
        for (int i = 0; i < N && i < 100; ++i)
            A.push_back(P[i].second);
        for (int i : A)
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
