class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int result = 0;
        for(int x : nums)
            for(int y : nums)
                if (abs(x - y) <= min(x, y))
                    result = max(result, x ^ y);
        return result;
    }
};
