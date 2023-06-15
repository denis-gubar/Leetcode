class Solution {
public:
    long long matrixSumQueries(int N, vector<vector<int>>& queries) {
        long long result = 0;
        unordered_set<int> row, col;
        int Q = queries.size();
        for (int q = Q - 1; q >= 0; --q)
        {
            int const& type = queries[q][0];
            int const& index = queries[q][1];
            int const& val = queries[q][2];
            if (type == 0)
            {
                if (row.insert(index).second)
                    result += 1LL * val * (N - col.size());
            }
            else
            {
                if (col.insert(index).second)
                    result += 1LL * val * (N - row.size());                
            }
        }
        return result;
    }
};
