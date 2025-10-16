class Solution {
public:
    struct UnionFind
    {
        vector<int> id, groupSize;
        UnionFind(int N) : id(vector<int>(N)), groupSize(vector<int>(N, 1))
        {
            iota(id.begin(), id.end(), 0);
        }
        int root(int x)
        {
            while (x != id[x])
                x = id[x] = id[id[x]];
            return x;
        }
        bool find(int p, int q)
        {
            return root(p) == root(q);
        }
        void unite(int p, int q)
        {
            p = root(p), q = root(q);
            if (groupSize[p] < groupSize[q])
                id[p] = q, groupSize[q] += groupSize[p];
            else
                id[q] = p, groupSize[p] += groupSize[q];
        }
        void checkedUnite(int p, int q)
        {
            if (!find(p, q))
                unite(p, q);
        }
    };
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        long long result = 0;
        int const N = nums.size();
        UnionFind UF(N);
        for (vector<int> const& sw : swaps)
            UF.checkedUnite(sw[0], sw[1]);
        vector<vector<int>> A(N);
        vector<string> S(N);
        for (int i = 0; i < N; ++i)
        {
            int const R = UF.root(i);
            A[R].push_back(nums[i]);
            if (i % 2 == 0)
                S[R] += '1';
            else
                S[R] += '0';
        }
        for (int i = 0; i < N; ++i)
            if (i == UF.root(i))
            {
                sort(A[i].begin(), A[i].end());
                sort(S[i].begin(), S[i].end());
                int const K = S[i].size();
                for (int j = 0; j < K; ++j)
                    if (S[i][j] == '0')
                        result -= A[i][j];
                    else
                        result += A[i][j];
            }
        return result;
    }
};
