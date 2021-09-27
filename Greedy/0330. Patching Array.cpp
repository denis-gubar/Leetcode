class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int result = 0;
        long long next = 1;
        int pos = 0;
        nums.push_back(n);
        int N = nums.size();
        while(pos < N && next <= n)
        {
            if (next >= nums[pos])
                next += nums[pos], ++pos;
            else
                ++result, next += next;            
        }
        return result;
    }
};