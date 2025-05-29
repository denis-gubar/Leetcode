class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            int sum = 0;
            int x = nums[i];
            while (x > 0)
                sum += x % 10, x /= 10;
            if (sum == i)
                return i;
        }
        return -1;
    }
};
