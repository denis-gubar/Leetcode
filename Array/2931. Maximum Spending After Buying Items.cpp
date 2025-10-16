class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long result = 0;
        int N = values.size(), M = values[0].size();
        vector<int> A(N);
        for (int d = N * M; d > 0; --d)
        {
            int current = -1;
            for(int i = 0; i < N; ++i)
                if (A[i] < M && (current == -1 || values[i][A[i]] > values[current][A[current]]))
                    current = i;
            result += 1LL * d * values[current][A[current]];
            ++A[current];
        }
        return result;
    }
};
