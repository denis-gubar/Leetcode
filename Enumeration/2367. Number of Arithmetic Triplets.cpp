class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int result = 0;
        int N = nums.size();
        unordered_map<int, int> M;
        for (int i = 0; i < N; ++i)
            ++M[nums[i]];
        for (auto [key, value] : M)
        {
            int m = key;
            if (M.find(m - diff) != M.end() && M.find(m + diff) != M.end())
                result += M[m - diff] * M[m + diff];
        }
        return result;
    }
};
