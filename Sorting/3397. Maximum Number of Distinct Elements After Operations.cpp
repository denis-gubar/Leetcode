class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int result = 0;
        sort(nums.begin(), nums.end());
        int last = -(1 << 30);
        for (int x : nums)
            if (max(last + 1, x - k) <= x + k)
                ++result, last = max(last + 1, x - k);
        return result;
    }
};
