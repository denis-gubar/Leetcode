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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string result;
        int N = s1.size();
        UnionFind UF(26);
        vector<char> A(26);
        iota(A.begin(), A.end(), 'a');
        for (int i = 0; i < N; ++i)
            UF.checkedUnite(s1[i] - 'a', s2[i] - 'a');
        for(int i = 0; i < 26; ++i)
            A[UF.root(i)] = min<char>(A[UF.root(i)], i + 'a');
        for (int i = 0; i < 26; ++i)
            A[i] = A[UF.root(i)];
        for (char c : baseStr)
            result += A[c - 'a'];
        return result;
    }
};
