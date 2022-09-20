class Solution {
public:
    vector<int> calc(vector<vector<int>> const& conditions, int K)
    {
        int N = conditions.size();
        vector<int> result;
        vector<bool> visited(K);
        vector<unordered_set<int>> connectivity(K + 1), inv(K + 1);
        for (int i = 0; i < N; ++i)
        {
            int V = conditions[i][0] - 1;
            int U = conditions[i][1] - 1;
            connectivity[V].insert(U);
            inv[U].insert(V);
        }
        set<pair<int, int>> S;
        for (int i = 0; i < K; ++i)
            S.insert({ connectivity[i].size(), i });
        while (!S.empty())
        {
            int V = S.begin()->second;
            int C = S.begin()->first;
            S.erase(S.begin());
            if (C > 0)
                return {};
            result.push_back(V);
            for (int U : inv[V])
            {                
                S.erase({ connectivity[U].size(), U });
                connectivity[U].erase(V);
                S.insert({ connectivity[U].size(), U });
            }
            inv[V].clear();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    vector<vector<int>> buildMatrix(int K, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> A = calc(rowConditions, K);
        vector<int> B = calc(colConditions, K);
        if (A.empty() || B.empty())
            return {};
        vector<int> invA(K), invB(K);
        for (int i = 0; i < K; ++i)
            invA[A[i]] = invB[B[i]] = i;
        vector<vector<int>> result(K, vector<int>(K));
        for (int i = 0; i < K; ++i)
            result[invA[i]][invB[i]] = i + 1;
        return result;
    }
};
