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
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int const N = circles.size();
        int const XMIN = N;
        int const XMAX = N + 1;
        int const YMIN = N + 2;
        int const YMAX = N + 3;
        UnionFind UF(N + 4);
        for (int i = 0; i < N; ++i)
        {
            int const& x = circles[i][0];
            int const& y = circles[i][1];
            int const& r = circles[i][2];
            if (x - r <= 0)
                UF.checkedUnite(i, XMIN);
            if (x + r >= X)
                UF.checkedUnite(i, XMAX);
            if (y - r <= 0)
                UF.checkedUnite(i, YMIN);
            if (y + r >= Y)
                UF.checkedUnite(i, YMAX);
            for (int j = i + 1; j < N; ++j)
            {
                int const& x2 = circles[j][0];
                int const& y2 = circles[j][1];
                int const& r2 = circles[j][2];
                if (1LL * (x - x2) * (x - x2) + 1LL * (y - y2) * (y - y2) <= 1LL * (r + r2) * (r + r2))
                    UF.checkedUnite(i, j);
            }
        }
        return UF.root(XMIN) != UF.root(YMIN) && UF.root(XMAX) != UF.root(YMAX) &&
               UF.root(XMIN) != UF.root(XMAX) && UF.root(YMIN) != UF.root(YMAX);
    }
};
