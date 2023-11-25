static int F[50'002][17];
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int Q = queries.size();
        heights.push_back(1 << 30);
        int N = heights.size();
        vector<int> result(Q, -1);
        for (int i = 0; i < N; ++i)
            F[i][0] = heights[i];
        for (int j = 1; (1 << j) <= N; ++j)
            for (int i = 0, end = N - (1 << j); i <= end; ++i)
                F[i][j] = max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
        auto rmq = [N](int L, int R)
            {
                if (L == R)
                    return F[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return max(F[L][j], F[R - (1 << j) + 1][j]);
            };
        for (int q = 0; q < Q; ++q)
        {
            auto [left, right] = minmax(queries[q][0], queries[q][1]);
            if (left == right || heights[right] > heights[left])
            {
                result[q] = right;
                continue;
            }
            int a = right, b = N - 1, H = max(heights[left], heights[right]);
            while (a + 1 < b)
            {
                int m = (a + b) / 2;
                if (rmq(right, m) > H)
                    b = m;
                else
                    a = m;
            }
            if (b < N - 1)
                result[q] = b;
        }
        return result;
    }
};
