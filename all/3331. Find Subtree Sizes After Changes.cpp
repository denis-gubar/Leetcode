class Solution {
public:
    vector<vector<int>> children;
    vector<int> result;
    string s;
    int N;
    vector<vector<int>> A;
    vector<int> parent;
    void calc(int V)
    {
        A[s[V] - 'a'].push_back(V);
        for (int U : children[V])
            calc(U);
        A[s[V] - 'a'].pop_back();
        if (!A[s[V] - 'a'].empty())
            result[A[s[V] - 'a'].back()] += result[V];
        else if (V > 0)
            result[parent[V]] += result[V];
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        N = s.size();
        this->s = s;
        children = vector<vector<int>>(N);
        this->parent = parent;
        result = vector<int>(N, 1);
        A = vector<vector<int>>(26);
        for (int i = 1; i < N; ++i)
            children[parent[i]].push_back(i);
        calc(0);
        return result;
    }
};
