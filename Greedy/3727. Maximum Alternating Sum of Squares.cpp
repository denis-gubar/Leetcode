class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size();
        sort(nums.begin(), nums.end(), [](int a, int b)
            {
                return abs(a) < abs(b);
            });
        int a = 0, b = N - 1;
        while (a <= b)
        {
            result += 1LL * nums[b] * nums[b];
            --b;
            if (a > b)
                break;
            result -= 1LL * nums[a] * nums[a];
            ++a;
        }
        return result;
    }
};
