class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int P = points.size();
        vector<int> result(P);
        int N = rectangles.size();
        sort(rectangles.begin(), rectangles.end());
        vector<int> A;
        vector<vector<int>> R(101);
        for (int i = 0; i < N; ++i)
            R[rectangles[i][1]].push_back(rectangles[i][0]);
        for (int i = 1; i <= 100; ++i)
            sort(R[i].begin(), R[i].end());
        A.reserve(N);
        for (int H = 100; H > 0; --H)
        {
            copy(R[H].begin(), R[H].end(), back_inserter(A));
            sort(A.begin(), A.end());
            for(int i = 0; i < P; ++i)
                if (points[i][1] == H)
                {
                    int x = points[i][0];
                    result[i] = A.end() - lower_bound(A.begin(), A.end(), x);
                }
        }
        return result;
    }
};
