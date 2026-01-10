/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
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
    int numberOfCategories(int N, CategoryHandler* categoryHandler) {
        int result = N;
        UnionFind UF(N);
        for (int a = 0; a < N; ++a)
            for (int b = a + 1; b < N; ++b)
                if (categoryHandler->haveSameCategory(a, b))
                {
                    UF.unite(a, b);
                    --result;
                    break;
                }
        return result;
    }
};
