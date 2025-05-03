class Solution {
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int K) {
        int const N = nums.size();
        vector<int> result(N);
        sort(nums.begin(), nums.end());
        array const P{ 1, 10, 100, 1'000, 10'000, 100'000, 1'000'000 };
        vector<int> D(N);
        for (int i = 0; i < N; ++i)
            D[i] = *lower_bound(P.begin(), P.end(), nums[i] + 1);
        auto calc = [N](int mask, int r) -> int
            {
                return r * (1 << N) + mask;
            };
        vector<unordered_map<int, set<int>>> F(N + 1), G(N + 1);
        F[0][calc(0, 0)] = {};
        for (int i = 0; i < N; ++i)
            for (auto [s, v] : F[i])
            {
                int const mask = s % (1 << N);
                int const r = s / (1 << N);
                for(int ni = 0; ni < N; ++ni)
                    if ((mask & (1 << ni)) == 0)
                    {
                        int const nr = (r * D[ni] + nums[ni]) % K;
                        int const nmask = mask | (1 << ni);
                        int const x = calc(nmask, nr);
                        F[i + 1][x].insert(s);
                    }
            }
        int const STATE = calc((1 << N) - 1, 0);
        if (F[N].find(STATE) == F[N].end())
            return {};
        G[N][STATE] = F[N][STATE];
        for(int i = N; i > 0; --i)
            for (auto& [state, value] : G[i])
                for (int s : value)
                    G[i - 1][s] = F[i - 1][s];
        int state = calc(0, 0);
        for (int i = 0; i < N; ++i)
            for (auto [s, v] : G[i])
                if (s == state)
            {
                bool found = false;
                int const mask = s % (1 << N);
                int const r = s / (1 << N);
                for (int ni = 0; ni < N; ++ni)
                    if ((mask & (1 << ni)) == 0)
                    {
                        int const nr = (r * D[ni] + nums[ni]) % K;
                        int const nmask = mask | (1 << ni);
                        int const x = calc(nmask, nr);
                        if (G[i + 1][x].find(s) != G[i + 1][x].end())
                        {
                            result[i] = nums[ni];
                            found = true;
                            state = x;
                            break;
                        }
                    }
                if (found)
                    break;
            }
        return result;
    }
};
