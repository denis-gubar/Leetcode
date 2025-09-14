static unsigned short first[26];
static unsigned short last[26];
class Solution {
public:
    using ushort = unsigned short;
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
    bool maxSubstringLength(string s, int K) {
        ushort const N = s.size();
        vector<vector<ushort>> A(26);
        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));
        for (ushort i = 0; i < N; ++i)
        {
            ushort const c = s[i] - 'a';
            if (first[c] > N)
                first[c] = i;
            last[c] = i;
            A[c].push_back(i);
        }
        for (ushort c = 0; c < 26; ++c)
            if (!A[c].empty())
                A[c].push_back(N);
        UnionFind UF(27);
        for (ushort c = 0; c < 26; ++c)
        {
            if (A[c].empty())
                continue;
            for (ushort d = 0; d < 26; ++d)
            {
                if (c == d || A[d].empty() || first[d] < first[c] && last[c] < last[d])
                    continue;
                if (first[c] < first[d] && last[d] < last[c])
                {
                    if (*lower_bound(A[c].begin(), A[c].end(), first[d]) < last[d])
                        UF.checkedUnite(c, d);
                    else
                        UF.checkedUnite(c, 26);
                }
                else if (last[c] > first[d] && last[d] > first[c])
                    UF.checkedUnite(c, d);
            }
        }
        ushort groupCount = 0;
        for (ushort c = 0; c < 26; ++c)
            if (!A[c].empty() && !UF.find(c, 26) && c == UF.root(c))
                ++groupCount;
        if (groupCount == 1 && UF.groupSize[UF.root(26)] == 1)
            --groupCount;
        return groupCount >= K;
    }
};
