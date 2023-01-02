class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int const MOD = 1'000'000'007;
        long long result = 0;
        int N = arr.size();
        set<int> S;
        for (int i = -1; i <= N; ++i)
            S.insert(i);
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i)
            A[i] = { arr[i], i };
        sort(A.begin(), A.end());
        while (!A.empty())
        {
            pair<int, int> P = A.back(); A.pop_back();
            int const& value = P.first;
            int const& pos = P.second;
            S.erase(pos);
            auto it = S.lower_bound(pos);
            int left = *prev(it);
            int right = *it;
            result += 1LL * (right - pos) * (pos - left) * value;
        }
        return result % MOD;
    }
};
