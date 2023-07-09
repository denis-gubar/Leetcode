class Solution {
public:
    vector<int> countServers(int N, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int Q = queries.size();
        int L = logs.size();
        set<int> S;
        for (int i = 0; i < Q; ++i)
            S.insert(queries[i]);
        vector<int> LQ(S.begin(), S.end());
        vector<int> result(Q);
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b)
            {
                return a[1] < b[1];
            });
        logs.push_back({ N + 1, 1 << 30 });
        queue<pair<int, int>> D;
        unordered_map<int, int> M;
        unordered_map<int, int> R;
        int j = 0;
        for (int i = 0; i <= L; ++i)
        {
            int time = logs[i][1];
            while (j < LQ.size() && time > LQ[j])
            {
                while (!D.empty() && D.front().second < LQ[j] - x)
                {
                    pair<int, int> P = D.front(); D.pop();
                    if (M[P.first] == 1)
                        M.erase(P.first);
                    else
                        --M[P.first];
                }
                R[LQ[j]] = N - M.size();
                ++j;
            }
            ++M[logs[i][0]];
            D.push({ logs[i][0], logs[i][1] });
        }
        for (int i = 0; i < Q; ++i)
            result[i] = R[queries[i]];
        return result;
    }
};
