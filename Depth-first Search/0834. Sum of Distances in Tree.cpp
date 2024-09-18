class Solution {
public:
    vector<vector<int>> connectivity;
    vector<int> result, childrenCount, treeSum;
    int N;
    void calc(int V, int P)
    {
        for(int U : connectivity[V])
            if (U != P)
            {
                calc(U, V);
                childrenCount[V] += childrenCount[U];
                treeSum[V] += treeSum[U] + childrenCount[U];
            }
    }
    void calc2(int V, int P)
    {
        for (int U : connectivity[V])
            if (U != P)
            {
                result[U] += result[V] - childrenCount[U] + N - childrenCount[U];
                calc2(U, V);
            }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        this->N = N;
        result = vector<int>(N);
        connectivity = vector<vector<int>>(N);
        childrenCount = vector<int>(N, 1);
        treeSum = vector<int>(N);
        for (int i = 0; i < N - 1; ++i)
        {
            int const& V = edges[i][0];
            int const& U = edges[i][1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        calc(0, -1);
        result[0] = treeSum[0];
        calc2(0, -1);
        return result;
    }
};
