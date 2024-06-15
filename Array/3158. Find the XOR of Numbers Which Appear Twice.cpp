class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        for (auto [key, value] : M)
            if (value == 2)
                result ^= key;
        return result;
    }
};
