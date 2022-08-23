class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int N = edges.size();
        vector<long long> M(N);
        for (int i = 0; i < N; ++i)
            M[edges[i]] += i;
        return max_element(M.begin(), M.end()) - M.begin();
    }
};
