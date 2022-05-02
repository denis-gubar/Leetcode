class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int result = 0;
        for (int i = 1; i < N - 1; ++i)
            if (nums[0] < nums[i] && nums[i] < nums.back())
                ++result;
        return result;
    }
};
