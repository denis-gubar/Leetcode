class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int const N = rains.size();
        unordered_map<int, bool> visited;
        vector<int> result(N, -1);
        unordered_map<int, vector<int>> M;
        for (int i = 0; i < N; ++i)
            if (rains[i] > 0)
                M[rains[i]].push_back(i);
        for (auto& [key, value] : M)
            reverse(value.begin(), value.end());        
        set<pair<int, int>> S;
        for (int i = 0; i < N; ++i)
            if (rains[i] > 0)
            {
                int const& pos = rains[i];
                if (visited[pos])
                    return {};
                visited[pos] = true;
                M[pos].pop_back();
                if (M[pos].empty())
                    continue;
                S.insert({ M[pos].back(), pos });
            }
            else
            {
                int pos = 1;
                if (!S.empty())
                {
                    pair<int, int> P = *S.begin();
                    S.erase(S.begin());
                    pos = P.second;
                }
                visited[pos] = false;
                result[i] = pos;
            }
        return result;
    }
};
