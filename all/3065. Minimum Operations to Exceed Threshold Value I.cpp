class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = 0;
        for (int x : nums)
            if (x < k)
                ++result;        
        return result;
    }
};
