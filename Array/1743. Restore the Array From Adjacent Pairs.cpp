class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int N = adjacentPairs.size() + 1;
        vector<int> result;
        result.reserve(N);
        vector<vector<int>> A(2);
        A[0].reserve(N);
        A[1].reserve(N);
        unordered_map<int, vector<int>> connectivity;
        unordered_set<int> visited;
        for (vector<int> const& e : adjacentPairs)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        int R = adjacentPairs[0][0];
        visited.emplace(R);
        queue<int> Q;
        Q.push(R); Q.push(-1);
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            int i = Q.front(); Q.pop();
            for(int U : connectivity[V])
                if (visited.find(U) == visited.end())
                {
                    i += V == R;
                    visited.emplace(U);
                    Q.push(U); Q.push(i);
                    A[i].push_back(U);
                }
        }
        copy(A[0].rbegin(), A[0].rend(), back_inserter(result));
        result.push_back(R);
        copy(A[1].begin(), A[1].end(), back_inserter(result));
        return result;
    }
};
