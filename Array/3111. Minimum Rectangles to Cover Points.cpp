class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int N = points.size();
        int result = 0;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            A[i] = points[i][0];
        sort(A.begin(), A.end());
        int prev = -w - 1;
        for (int x : A)
        {
            if (prev + w >= x)
                continue;
            ++result;
            prev = x;
        }
        return result;
    }
};
