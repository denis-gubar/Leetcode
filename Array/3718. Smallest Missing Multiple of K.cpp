class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> S(nums.begin(), nums.end());
        for (int result = k; ; result += k)
            if (S.find(result) == S.end())
                return result;
        return -1;
    }
};
