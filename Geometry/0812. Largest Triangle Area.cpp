class Solution {
public:
    double largestTriangleArea( vector<vector<int>>& points ) {
        int best = 0, N = points.size();
        for(int i = 0; i < N; ++i)
            for(int j = i + 1; j < N; ++j)
                for (int k = j + 1; k < N; ++k)
                {
                    best = max( best, 
                                abs( (points[i][0] - points[k][0]) * (points[j][1] - points[i][1]) -
                                     (points[i][0] - points[j][0]) * (points[k][1] - points[i][1]) ) );
                }
        return 0.5 * best;
    }
};