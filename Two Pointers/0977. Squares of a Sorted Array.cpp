class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int N = nums.size();
        vector<int> result;
        result.reserve(N);
        int right = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int left = right - 1;
        while(left >= 0 || right < N)
            if (left >= 0 && (right == N || nums[left] * nums[left] < nums[right] * nums[right]))
                result.push_back(nums[left] * nums[left]), --left;
            else
                result.push_back(nums[right] * nums[right]), ++right;
        return result;
    }
};