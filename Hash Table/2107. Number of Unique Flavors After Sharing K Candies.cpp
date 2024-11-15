class Solution {
public:
    int shareCandies(vector<int>& candies, int K) {
        int const N = candies.size();
        unordered_map<int, int> M;
        auto add = [&M](int x)
            {
                ++M[x];
            };
        auto remove = [&M](int x)
            {
                if (--M[x] == 0)
                    M.erase(x);
            };
        for (int i = K; i < N; ++i)
            add(candies[i]);
        size_t result = M.size();
        for (int i = 0; i + K < N; ++i)
        {
            add(candies[i]);
            remove(candies[i + K]);
            result = max(result, M.size());
        }
        return result;
    }
};
