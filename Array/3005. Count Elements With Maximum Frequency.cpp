class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        int x = 0;
        for (auto [key, value] : M)
            if (value > x)
                x = value;
        for (auto [key, value] : M)
            if (value == x)
                result += x;
        return result;
    }
};
