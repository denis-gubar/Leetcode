class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int result = 0;
        int best = 0;
        for (vector<int> const& D : dimensions)
        {
            int const& a = D[0];
            int const& b = D[1];
            int d = a * a + b * b;
            if (d > best)
                best = d, result = a * b;
            else if (d == best)
                result = max(result, a * b);
        }
        return result;
    }
};
