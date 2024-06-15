class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int N = queries.size();
        vector<int> result(N);
        unordered_map<int, int> colors;
        unordered_map<int, int> A;
        int balance = 0;
        for (int i = 0; i < N; ++i)
        {
            int const& x = queries[i][0];
            int const& y = queries[i][1];
            if (A.find(x) != A.end() && A[x] == y)
            {
                result[i] = balance;
                continue;
            }
            if (A.find(x) == A.end())
            {
                A[x] = y;
                if (++colors[y] == 1)
                    ++balance;
                result[i] = balance;
                continue;
            }
            if (--colors[A[x]] == 0)
                --balance;
            A[x] = y;
            if (++colors[y] == 1)
                ++balance;
            result[i] = balance;
        }
        return result;
    }
};
