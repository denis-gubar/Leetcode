class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        for (auto [key, value] : M)
            if (value > 2)
                return false;
        return true;
    }
};
