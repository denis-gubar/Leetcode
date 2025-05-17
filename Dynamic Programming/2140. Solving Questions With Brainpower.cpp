static long long F[100'001];
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        memset(F, 0, sizeof(F));
        int const N = questions.size();
        long long best = 0, result = 0;
        auto update = [&result](long long& x, long long value)
            {
                if (x < value)
                {
                    x = value;
                    if (result < x)
                        result = x;
                }
            };
        for (int i = 0; i < N; ++i)
        {
            int const& points = questions[i][0];
            int const brainpower = questions[i][1] + 1;
            best = max(best, F[i]);
            update(F[min(i + brainpower, N)], best + points);
        }
        return result;
    }
};
