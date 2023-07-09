class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> result{ 0, 0 };
        int N = mat.size(), M = mat[0].size();
        for (int i = 0; i < N; ++i)
        {
            int current = 0;
            for (int j = 0; j < M; ++j)
                if (mat[i][j] == 1)
                    ++current;
            if (result[1] < current)
                result[0] = i, result[1] = current;
        }
        return result;
    }
};
