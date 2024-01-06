class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;
        for (int x : nums)
            count += x % 2 == 0;
        return count > 1;
    }
};
