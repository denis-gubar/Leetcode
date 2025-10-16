class Solution {
public:
    int countUnguarded(int N, int M, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int result = 0;
        vector<vector<pair<int, int>>> H(N);
        vector<vector<pair<int, int>>> V(M);
        for (int i = 0; i < N; ++i)
            H[i].push_back({ -1, 1 }), H[i].push_back({ M, 1 });
        for (int j = 0; j < M; ++j)
            V[j].push_back({ -1, 1 }), V[j].push_back({ N, 1 });
        for (int i = 0; i < guards.size(); ++i)
        {
            int const& row = guards[i][0];
            int const& col = guards[i][1];
            H[row].push_back({ col, 0 });
            V[col].push_back({ row, 0 });
        }
        for (int i = 0; i < walls.size(); ++i)
        {
            int const& row = walls[i][0];
            int const& col = walls[i][1];
            H[row].push_back({ col, 1 });
            V[col].push_back({ row, 1 });
        }
        for (int i = 0; i < N; ++i)
            sort(H[i].begin(), H[i].end());
        for (int j = 0; j < M; ++j)
            sort(V[j].begin(), V[j].end());
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                auto itH = lower_bound(H[i].begin(), H[i].end(), pair<int, int>{ j, 0 });
                if (itH->second == 0)
                    continue;
                if(itH->second == 1 && itH->first == j)
                    continue;
                --itH;
                if (itH->second == 0)
                    continue;
                auto itV = lower_bound(V[j].begin(), V[j].end(), pair<int, int>{i, 0});
                if (itV->second == 0)
                    continue;
                --itV;
                if (itV->second == 0)
                    continue;
                ++result;
            }
        return result;
    }
};
