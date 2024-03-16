class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int K) {
        long long result = 0;
        int N = happiness.size();
        sort(happiness.begin(), happiness.end());
        for (int i = 0, j = N - 1; i < K; ++i, --j)
            result += max(happiness[j] - i, 0);
        return result;
    }
};
