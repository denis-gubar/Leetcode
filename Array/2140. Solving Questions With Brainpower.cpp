class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long result = 0, best = 0;
        int N = questions.size();
        vector<long long> A(N + 1);
        for (int i = 0; i < N; ++i)
        {
			int const& points = questions[i][0];
			int brainpower = questions[i][1] + 1;
            best = max(best, A[i]);
            A[min(i + brainpower, N)] = max(A[min(i + brainpower, N)], best + points);
            result = max(result, A[min(i + brainpower, N)]);
        }
        return result;
    }
};
