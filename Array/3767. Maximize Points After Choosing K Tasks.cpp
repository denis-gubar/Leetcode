class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int K) {
        long long result = 0;
        int const N = technique1.size();
        vector<pair<int, int>> P(N);
        for (int i = 0; i < N; ++i)
            P[i] = { technique2[i] - technique1[i], i };
        sort(P.begin(), P.end());
        for (int i = 0; i < K; ++i)
            result += technique1[P[i].second];
        for (int i = K; i < N; ++i)
            if (P[i].first > 0)
                result += technique2[P[i].second];
            else
                result += technique1[P[i].second];
        return result;
    }
};
