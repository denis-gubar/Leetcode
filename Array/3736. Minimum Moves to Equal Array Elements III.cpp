class Solution {
public:
    int minMoves(vector<int>& nums) {
        int result = 0;
        int t = *max_element(nums.begin(), nums.end());
        for (int x : nums)
            result += t - x;
        return result;
    }
};
