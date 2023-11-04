class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int result = 0;
        int N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            unordered_set<int> S;
            for (int j = i; j < N; ++j)
            {
                S.insert(nums[j]);
                result += S.size() * S.size();
            }
        }
        return result;
    }
};
