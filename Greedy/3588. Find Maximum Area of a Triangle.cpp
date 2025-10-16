class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        long long result = 0;
        int const N = coords.size();
        unordered_map<int, int> A, B, C, D;
        int minX = 1 << 30, maxX = -(1 << 30);
        int minY = 1 << 30, maxY = -(1 << 30);
        for (int i = 0; i < N; ++i)
        {
            int const& x = coords[i][0];
            int const& y = coords[i][1];
            minX = min(minX, x);
            maxX = max(maxX, x);
            minY = min(minY, y);
            maxY = max(maxY, y);
            if (A.find(x) == A.end())
                A[x] = B[x] = y;
            else
                A[x] = min(A[x], y), B[x] = max(B[x], y);
            if (C.find(y) == C.end())
                C[y] = D[y] = x;
            else
                C[y] = min(C[y], x), D[y] = max(D[y], x);
        }
        if (A.size() == 1)
            return -1;
        for (auto [x, value] : A)
        {
            result = max(result, 1LL * (x - minX) * (B[x] - A[x]));
            result = max(result, 1LL * (maxX - x) * (B[x] - A[x]));
        }
        for (auto [y, value] : C)
        {
            result = max(result, 1LL * (y - minY) * (D[y] - C[y]));
            result = max(result, 1LL * (maxY - y) * (D[y] - C[y]));
        }
        if (result == 0)
            result = -1;
        return result;
    }
};
