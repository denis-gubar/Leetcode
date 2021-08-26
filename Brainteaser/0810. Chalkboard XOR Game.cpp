class Solution {
public:
    bool xorGame( vector<int>& nums ) {
        int N = nums.size(), total = 0;
        for (int x : nums)
            total ^= x;
        return N % 2 == 0 || total == 0;
    }
};