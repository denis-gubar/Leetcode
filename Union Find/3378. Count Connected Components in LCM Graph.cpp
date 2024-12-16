static int F[200'001];
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
    int countComponents(vector<int>& nums, int threshold) {
        vector<int> A(nums);
        sort(A.begin(), A.end());
        A.resize(unique(A.begin(), A.end()) - A.begin());
        int result = 0;
        while (!A.empty() && A.back() > threshold)
            A.pop_back(), ++result;
        int const N = A.size();
        UnionFind UF(N);
        memset(F, -1, sizeof(F));
        for (int i = 0; i < N; ++i)
            F[A[i]] = i;
        for (int i = N - 1; i >= 0; --i)
        {
            for (int x = A[i] + A[i]; x <= threshold; x += A[i])
                if (F[x] < 0)
                    F[x] = F[A[i]];
                else
                    UF.checkedUnite(i, F[x]);
        }
        for (int i = 0; i < N; ++i)
            if (UF.root(i) == i)
                ++result;
        return result;
    }
};
