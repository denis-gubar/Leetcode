class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int, int> M;
        vector<int> result{ -1, -1 };
        for (int x : nums)
            ++M[x];
        for(auto [x, xv] : M)
            for(auto [y, yv] : M)
                if (x < y && M[x] != M[y])
                {
                    if (result[0] == -1 || result[0] > x)
                        result[0] = x, result[1] = y;
                    else if (result[0] == x && result[1] > y)
                        result[1] = y;
                }
        return result;
    }
};
