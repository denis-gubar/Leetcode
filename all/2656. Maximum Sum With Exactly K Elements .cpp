class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int N = nums.size();
        int x = *max_element(nums.begin(), nums.end());
        int result = x;
        for (int i = 1; i < k; ++i)
            result += i + x;
        return result;
    }
};
