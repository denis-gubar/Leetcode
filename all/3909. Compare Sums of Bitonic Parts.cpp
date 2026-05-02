class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int pos = 1;
        while (nums[pos - 1] < nums[pos] && nums[pos] < nums[pos + 1])
            ++pos;
        long long left = accumulate(nums.begin(), nums.begin() + pos, 0LL);
        long long right = accumulate(nums.begin() + pos + 1, nums.end(), 0LL);
        if (left == right)
            return -1;
        if (left > right)
            return 0;
        return 1;
    }
};
