class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int N = costs.size();
        if (!N) return 0;
        vector<vector<int>> M(N, vector<int>(3, 1 << 30));
        M[0] = costs[0];
        for(int i = 1; i < N; ++i)
            for(int j = 0; j < 3; ++j)
                for(int k = 0; k < 3; ++k)
                    if (j != k)
                        M[i][k] = min(M[i][k], M[i - 1][j] + costs[i][k]);
        return *min_element(M[N - 1].begin(), M[N - 1].end());                        
    }
};