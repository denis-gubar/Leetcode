class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        for (auto [key, value] : M)
            if (value % k == 0)
                result += key * value;
        return result;
    }
};
