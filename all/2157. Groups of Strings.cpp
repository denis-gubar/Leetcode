static int M[1 << 26];

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
    vector<int> groupStrings(vector<string>& words) {
        vector<int> result;
        int N = words.size();
        memset(M, -1, sizeof(M));
        UnionFind uf(N);
        for (int i = 0; i < N; ++i)
        {
            int hash = 0;
            for (char c : words[i])
                hash |= 1 << (c - 'a');
            for (int c = -1; c < 26; ++c)
                if (c < 0 || hash & (1 << c))
                {
                    int newHash = hash;
                    if (c >= 0)
                        newHash = hash ^ (1 << c);
                    if (M[newHash] >= 0)
                        uf.checkedUnite(i, M[newHash]);
                    else
                        M[newHash] = i;
                }
        }
        int bestSize = 0;
        int count = 0;
        for (int i = 0; i < N; ++i)
        {
            bestSize = max(bestSize, uf.groupSize[i]);
            count += uf.root(i) == i;
        }
        return {count, bestSize};
    }
};
