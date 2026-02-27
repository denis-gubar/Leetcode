class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> M, M2;
        for (int x : nums)
            ++M[x];
        for (auto [key, value] : M)
            ++M2[value];
        for (int x : nums)
            if (M2[M[x]] == 1)
                return x;
        return -1;
    }
};
