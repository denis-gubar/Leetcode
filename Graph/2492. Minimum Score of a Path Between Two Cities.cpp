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
    int minScore(int N, vector<vector<int>>& roads) {
        UnionFind UF(N + 1);
        int result = 10'000;
        for (vector<int> const& road : roads)
        {
            int const& V = road[0];
            int const& U = road[1];
            int const& distance = road[2];
            UF.checkedUnite(V, U);
        }
        for (vector<int> const& road : roads)
        {
            int const& V = road[0];
            int const& U = road[1];
            int const& distance = road[2];
            if (UF.root(V) == UF.root(1))
                result = min(result, distance);
        }
        return result;
    }
};
