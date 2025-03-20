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
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size())
            return false;
        UnionFind UF(4'000);
        unordered_map<string, int> M;
        for (vector<string> const& w : similarPairs)
        {
            if (M.find(w[0]) == M.end())
                M[w[0]] = M.size();
            if (M.find(w[1]) == M.end())
                M[w[1]] = M.size();
            UF.checkedUnite(M[w[0]], M[w[1]]);
        }
        int const N = sentence1.size();
        for (int i = 0; i < N; ++i)
        {
            if (M.find(sentence1[i]) == M.end())
                M[sentence1[i]] = M.size();
            if (M.find(sentence2[i]) == M.end())
                M[sentence2[i]] = M.size();
            if (UF.root(M[sentence1[i]]) != UF.root(M[sentence2[i]]))
                return false;
        }
        return true;
    }
};
