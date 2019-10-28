class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int N = nums.size();
        int a = N, b = 0;
        while(b < N)
        {
            if (nums[b] != 1 && a < N)
            {
                result = max(result, b - a);
                a = N;
            }
            if (nums[b] == 1 && a == N)
                a = b;
            ++b;
        }
        if (a < N)
            result = max(result, b - a);
        return result;
    }
};