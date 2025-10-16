class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int result = 0;
        for (int x : nums)
            result |= x;
        return result;
    }
};
