class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int N = points.size();
        if (N < 3)
            return N;
        int result = 2;
        auto isTriangle = [&points](int a, int b, int c) -> bool
        {
            int square = 0;
            square += (points[b][0] - points[a][0]) * (points[b][1] + points[a][1]);
            square += (points[c][0] - points[b][0]) * (points[c][1] + points[b][1]);
            square += (points[a][0] - points[c][0]) * (points[a][1] + points[c][1]);
            return square != 0;
        };
        for(int a = 0; a < N; ++a)
            for (int b = a + 1; b < N; ++b)
            {
                int current = 2;
                for (int c = b + 1; c < N; ++c)
                    if (!isTriangle(a, b, c))
                        ++current;
                result = max(result, current);
            }
        return result;
    }
};
