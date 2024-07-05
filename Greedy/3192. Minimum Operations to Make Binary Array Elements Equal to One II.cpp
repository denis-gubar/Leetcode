class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        for(int x : nums)
            if (x % 2 == result % 2)
                ++result;
        return result;
    }
};
