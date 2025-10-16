static long long F[100'001];
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int N = nums.size();
        vector<pair<int, int>> P(N);
        for (int i = 0; i < N; ++i)
            P[i] = { nums[i] - i, i };
        memset(F, -100, sizeof(F));
        sort(P.begin(), P.end());
        set<int> S;
        for (int i = 0; i < N; ++i)
        {
            int const& pos = P[i].second;
            int const& value = nums[pos];
            if (value <= 0)
                continue;
            auto it = S.insert(pos).first;
            if (it == S.begin())
                F[pos] = value;
            else
                F[pos] = F[*prev(it)] + value;
            auto nit = next(it);
            while (nit != S.end() && F[*nit] <= F[pos])
                nit = S.erase(nit);
        }
        long long result = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < N; ++i)
            result = max(result, F[i]);
        return result;
    }
};
