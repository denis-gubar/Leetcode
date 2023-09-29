class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        for (int i = 0; i < N - 1; ++i)
            if (nums[i] != i + 1)
                return false;
        return nums.back() == N - 1;
    }
};
