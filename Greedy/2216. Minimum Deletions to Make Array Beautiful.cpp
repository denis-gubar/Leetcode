class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int result = 0;
        reverse(nums.begin(), nums.end());
        while (nums.size() > 1)
        {
            int N = nums.size();
            if (nums[N - 1] != nums[N - 2])
                nums.pop_back(), nums.pop_back();
            else
                nums.pop_back(), ++result;
        }
        result += nums.size();
        return result;
    }
};
