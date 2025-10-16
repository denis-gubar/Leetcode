class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result = 0;
        for (int x : nums)
            if (x % 2 == 0)
                result |= x;
        return result;
    }
};
