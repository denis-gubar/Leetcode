class Solution {
public:
    int maxProduct(vector<int>& nums, int K, int limit) {
        int result = -1;
        int const N = nums.size();
        vector<vector<unordered_map<unsigned short, unordered_set<unsigned short>>>> F(N + 1, vector<unordered_map<unsigned short, unordered_set<unsigned short>>>(2));
        F[0][0][0].insert(limit + 2);
        for (int i = 0; i < N; ++i)
        {
            vector<unordered_map<unsigned short, unordered_set<unsigned short>>> const& G = F[i];
            vector<unordered_map<unsigned short, unordered_set<unsigned short>>>& NG = F[i + 1];
            NG[0] = G[0];
            NG[1] = G[1];
            for (auto const& [sum, productList] : G[0])
                for (unsigned short product : productList)
                {
                    unsigned short x = (product > limit + 1) ? 1 : product;
                    x *= nums[i];
                    NG[1][sum + nums[i]].insert(min<unsigned short>(limit + 1, x));
                }
            for (auto const& [sum, productList] : G[1])
                for (unsigned short product : productList)
                {
                    unsigned short x = product * nums[i];
                    NG[0][sum - nums[i]].insert(min<unsigned short>(limit + 1, x));
                }
        }
        for (int z = 0; z < 2; ++z)
            if (!F[N][z].empty())
                for (unsigned short product : F[N][z][K])
                    if (product <= limit)
                        result = max<int>(result, product);
        return result;
    }
};
