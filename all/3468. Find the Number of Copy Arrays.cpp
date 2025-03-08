class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int const N = original.size();
        int L = -2'000'000'001, R = 2'000'000'001;
        for (int i = 0; i < N; ++i)
        {
            int const left = bounds[i][0] - original[i];
            int const right = bounds[i][1] - original[i];
            if (right < L || R < left)
                return 0;
            L = max(L, left);
            R = min(R, right);
            if (L > R)
                return 0;
        }
        return R - L + 1;
    }
};
