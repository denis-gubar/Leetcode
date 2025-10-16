static int M[100'001];
class Solution {
public:
    long long sumOfAncestors(int N, vector<vector<int>>& edges, vector<int>& nums) {
        long long result = 0;
        vector<vector<int>> connectivity(N);
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
        }
        vector<bool> isPerfect(100'001);
        for (int i = 0; i * i <= 100'000; ++i)
            isPerfect[i * i] = true;
        int perfectCount = 0;
        memset(M, 0, sizeof(M));
        auto dfs = [&](this const auto& self, int V, int P) -> void
            {
                perfectCount += isPerfect[nums[V]];
                for(int U : connectivity[V])
                    if (U != P)
                    {
                        if (isPerfect[nums[U]])
                            result += perfectCount;
                        else
                        {
                            int val = nums[U];
                            for (int x = 2; x * x <= val; ++x)
                                if (val % (x * x) == 0)
                                    while (val % (x * x) == 0)
                                        val /= x * x;
                            for (int x = 1; x * x * val <= 100'000; ++x)
                                result += M[x * x * val];
                        }
                        ++M[nums[U]];
                        self(U, V);
                        --M[nums[U]];
                    }
                perfectCount -= isPerfect[nums[V]];
            };
        M[nums[0]] = 1;
        dfs(0, -1);
        return result;
    }
};
