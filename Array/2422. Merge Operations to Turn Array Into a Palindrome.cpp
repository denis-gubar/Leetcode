class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        long long left = 0, right = 0;
        int a = 0, b = N - 1;
        while (a <= b)
        {
            if (left == right)
            {
                left += nums[a];
                right += nums[b];
                ++a, --b;
                continue;
            }
            if (left < right)
            {
                ++result;
                left += nums[a];
                ++a;
                continue;
            }
            ++result;
            right += nums[b];
            --b;
        }
        result += left != right;
        return result;
    }
};
