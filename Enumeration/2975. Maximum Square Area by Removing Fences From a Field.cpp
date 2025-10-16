class Solution {
public:
    int const MOD = 1'000'000'007;
    int maximizeSquareArea(int N, int M, vector<int>& hFences, vector<int>& vFences) {
        long long result = -1;
        hFences.push_back(1);
        vFences.push_back(1);
        hFences.push_back(N);
        vFences.push_back(M);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        int NH = hFences.size();
        int NV = vFences.size();
        vector<int> A(NH), B(NV);
        for (int i = 1; i < NH; ++i)
            A[i] = A[i - 1] + (hFences[i] - hFences[i - 1]);
        for (int i = 1; i < NV; ++i)
            B[i] = B[i - 1] + (vFences[i] - vFences[i - 1]);
        unordered_set<int> S;
        for (int i = 0; i < NH; ++i)
            for (int j = i + 1; j < NH; ++j)
                S.insert(A[j] - A[i]);
        for (int i = 0; i < NV; ++i)
            for (int j = i + 1; j < NV; ++j)
                if (S.find(B[j] - B[i]) != S.end())
                    result = max(result, 1LL * (B[j] - B[i]) * (B[j] - B[i]));
        if (result > 0)
            result %= MOD;
        return result;
    }
};
