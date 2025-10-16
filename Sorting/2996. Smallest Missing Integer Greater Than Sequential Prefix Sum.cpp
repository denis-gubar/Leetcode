class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int result = nums[0];
        unordered_set<int> S(nums.begin(), nums.end());
        int N = nums.size();
        for (int i = 1; i < N; ++i)
            if (nums[i] == nums[i - 1] + 1)
                result += nums[i];
            else
                break;
        while (S.find(result) != S.end())
            ++result;
        return result;
    }
};
