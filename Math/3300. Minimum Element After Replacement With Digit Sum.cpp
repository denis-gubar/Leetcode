class Solution {
public:
    int minElement(vector<int>& nums) {
        int result = 1 << 20;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            int sum = 0, x = nums[i];
            while (x > 0)
                sum += x % 10, x /= 10;
            result = min(result, sum);
        }
        return result;
    }
};
