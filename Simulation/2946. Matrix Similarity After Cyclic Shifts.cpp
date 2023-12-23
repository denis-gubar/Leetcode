class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> G = mat;
        int N = mat.size(), M = mat[0].size();
        k %= M;
        if (k == 0)
            return true;
        for (int i = 0; i < N; i += 2)
        {
            auto& row = mat[i];
            rotate(row.begin(), row.begin() + k, row.end());
        }
        for (int i = 1; i < N; i += 2)
        {
            auto& row = mat[i];
            rotate(row.begin(), row.begin() + (M - k) % M, row.end());
        }
        return G == mat;
    }
};
