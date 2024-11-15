class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long result = 0;
        int const N = nums.size();
        sort(nums.begin(), nums.end());
        for (int a = N - 1, b = a, i = 0; i < N - 1; ++i)
        {
            a = max(a, i + 1);
            while (a > i + 1 && nums[i] + nums[a - 1] >= lower)
                --a;
            b = max(a, b);
            while (b > i + 1 && nums[i] + nums[b] > upper)
                --b;
            if (nums[i] + nums[a] < lower || nums[i] + nums[b] > upper)
                continue;
            result += b - a + 1;
        }
        return result;
    }
};

