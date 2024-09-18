static int const MOD = 1'000'000'007;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long result = 0, balance = 0;
        int const N = arr.size();
        vector<int> S;
        S.reserve(N + 1);
        //Adding 0 value on virtual position -1 in arr
        S.push_back(-1);
        for (int pos = 0; pos < N; ++pos)
        {
            while (S.back() >= 0 && arr[S.back()] > arr[pos])
            {
                int oldPos = S.back();
                S.pop_back();
                balance -= (0LL + oldPos - S.back()) * arr[oldPos];
            }
            balance += (0LL + pos - S.back()) * arr[pos];
            S.push_back(pos);
            result += balance;
        }
        return result % MOD;
    }
};
