class Solution {
public:
    long long minimalKSum(vector<int>& nums, long long k) {
        long long result = 0;
        nums.push_back(0);
        sort(nums.begin(), nums.end());        
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int N = nums.size();
        for (int i = 1; i < N && k > 0; ++i)
        {
            long long a = nums[i - 1] + 1;
            long long b = nums[i] - 1;
            if (a <= b)
            {
                long long count = min(k, b - a + 1);
                if (count == k)
                    b = a + k - 1;
                result += (a + b) * count / 2;
                k -= count;
            }
        }
        if (k > 0)
            result += (nums.back() + nums.back() + k + 1) * k / 2;
        return result;
    }
};
