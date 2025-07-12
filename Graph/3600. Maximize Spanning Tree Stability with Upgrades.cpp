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
    int maxStability(int N, vector<vector<int>>& edges, int K) {
        int MAX_STRENGTH = 200'001;
        int const E = edges.size();
        vector<vector<int>> A(2);
        A[0].reserve(E), A[1].reserve(E);
        UnionFind UF(N);
        for (int i = 0; i < E; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            int const& S = edges[i][2];
            int const& MUST = edges[i][3];
            A[MUST].push_back(i);
            if (MUST)
            {
                if (UF.root(V) == UF.root(U))
                    return -1;
                UF.unite(V, U);
                MAX_STRENGTH = min(MAX_STRENGTH, S);
            }
        }
        for (int i : A[0])
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            UF.checkedUnite(V, U);
        }
        if (UF.groupSize[UF.root(0)] != N)
            return -1;
        sort(A[0].begin(), A[0].end(), [&edges](int a, int b)
            {
                return edges[a][2] < edges[b][2];
            });
        int a = 0, b = MAX_STRENGTH + 1;
        auto calc = [&A, &edges, N, K](int m) -> bool
            {
                UnionFind UF(N);
                for (int i : A[1])
                {
                    int const& V = edges[i][0];
                    int const& U = edges[i][1];
                    UF.unite(V, U);
                }
                int edgesToAdd = N - 1 - A[1].size();
                int doubleEdges = K;
                for (int k = 0, pos = static_cast<int>(A[0].size()) - 1; k < edgesToAdd; ++k)
                {
                    while (true)
                    {
                        if (pos < 0)
                            return false;
                        int const i = A[0][pos];
                        int const& V = edges[i][0];
                        int const& U = edges[i][1];
                        int const& S = edges[i][2];
                        --pos;
                        if (UF.root(V) != UF.root(U))
                        {
                            if (S * 2 < m)
                                return false;
                            if (S < m && --doubleEdges < 0)
                                return false;
                            UF.unite(V, U);
                            break;
                        }
                    }
                }
                return true;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};
