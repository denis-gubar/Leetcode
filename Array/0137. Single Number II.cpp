class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r1 = 0, r2 = 0;
        for (int x : nums)
        {
            int n1 = (r1 ^ x) & (~r2);
            int n2 = (r2 ^ x) & (~n1);
            r1 = n1, r2 = n2;
        }
        return r1;
    }
};
