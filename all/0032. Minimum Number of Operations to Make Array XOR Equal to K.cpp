class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = 0;
        int N = nums.size();
        int total = k;
        for (int x : nums)
            total ^= x;
        while (total > 0)
        {
            total &= total - 1;
            ++result;
        }
        return result;
    }
};
