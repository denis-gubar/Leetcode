class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int N = nums.size();
        unordered_set<int> S;
        for (int i = 0; i + 1 < N; ++i)
        {
            int sum = nums[i] + nums[i + 1];
            if (!S.insert(sum).second)
                return true;
        }
        return false;
    }
};