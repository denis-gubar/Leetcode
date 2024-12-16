class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int const N = pairs.size();
        unordered_map<int, vector<int>> connectivity;
        unordered_map<int, int> nodeDegree;
        vector<int> path;
        connectivity.reserve(N);
        nodeDegree.reserve(N);
        path.reserve(N + 1);

        for (vector<int> const& edge : pairs)
        {
            int const& start = edge[0], end = edge[1];
            connectivity[start].push_back(end);
            ++nodeDegree[start];
            --nodeDegree[end];
        }

        int V = nodeDegree.begin()->first;
        for (auto [key, value] : nodeDegree)
            if (value == 1)
            {
                V = key;
                break;
            }

        vector<int> S;
        S.reserve(N);
        S.push_back(V);
        while (!S.empty()) {
            V = S.back();
            if (connectivity[V].empty()) 
            {
                path.push_back(V);
                S.pop_back();
            }
            else 
            {
                int const U = connectivity[V].back();
                connectivity[V].pop_back();
                S.push_back(U);
            }
        }

        vector<vector<int>> result;
        result.reserve(N);

        for (int i = N - 1; i >= 0; --i)
            result.push_back({ path[i + 1], path[i] });
        return result;
    }
};
