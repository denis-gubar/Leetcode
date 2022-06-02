class Solution {
public:
    long long maximumImportance(int N, vector<vector<int>>& roads) {
        long long result = 0;
        vector<int> A(N);
        for (int i = 0; i < roads.size(); ++i)
        {
            int const& V = roads[i][0];
            int const& U = roads[i][1];
            ++A[V], ++A[U];
        }
        sort(A.begin(), A.end());
        for (int i = 0; i < N; ++i)
            result += 1LL * (i + 1) * A[i];
        return result;
    }
};
