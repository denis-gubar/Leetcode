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
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int result = 0;
        int const N = picture.size(), M = picture[0].size();
        UnionFind UF(N);
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (picture[i] == picture[j])
                {
                    UF.unite(i, j);
                    break;
                }
        vector<int> rows(N), columns(M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (picture[i][j] == 'B')
                    ++rows[i], ++columns[j];
        for (int i = 0; i < N; ++i)
            if (rows[i] == target)
                for (int j = 0; j < M; ++j)
                    if (columns[j] == target)
                    {
                        bool isOk = true;
                        int const group = UF.root(i);
                        for(int k = 0; isOk && k < N; ++k)
                            if (picture[k][j] == 'B')
                                isOk = group == UF.root(k);
                        result += isOk;
                    }
        return result;
    }
};
