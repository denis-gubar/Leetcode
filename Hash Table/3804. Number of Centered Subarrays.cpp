class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            unordered_set<int> S;
            int sum = 0;
            for (int j = i; j < N; ++j)
            {
                sum += nums[j];
                S.insert(nums[j]);
                result += S.find(sum) != S.end();
            }
        }
        return result;
    }
};
