class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
        unordered_set<int> S;
        for (int x : nums)
            S.insert(x);
        for (int i = 1; i < 1'001; ++i)
            if (S.find(i) != S.end() && S.find(-i) != S.end())
                result = i;
        return result;
    }
};
