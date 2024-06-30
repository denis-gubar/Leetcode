class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        for (int x : nums)
            result += (x % 3 != 0);
        return result;
    }
};
