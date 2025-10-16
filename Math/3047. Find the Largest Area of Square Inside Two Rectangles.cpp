class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long result = 0;
        int N = bottomLeft.size();
        for (int i = 0; i < N; ++i)
        {
            int const& x1 = bottomLeft[i][0];
            int const& y1 = bottomLeft[i][1];
            int const& x2 = topRight[i][0];
            int const& y2 = topRight[i][1];
            for (int j = i + 1; j < N; ++j)
            {
                int const& x3 = bottomLeft[j][0];
                int const& y3 = bottomLeft[j][1];
                int const& x4 = topRight[j][0];
                int const& y4 = topRight[j][1];
                int s = max(0, min(min(x2, x4) - max(x1, x3), min(y2, y4) - max(y1, y3)));
                result = max(result, 1LL * s * s);
            }
        }
        return result;
    }
};
