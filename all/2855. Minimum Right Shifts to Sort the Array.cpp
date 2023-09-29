class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            if (is_sorted(nums.begin(), nums.end()))
                return i;
            rotate(nums.begin(), nums.begin() + N - 1, nums.end());
        }
        return -1;
    }
};
