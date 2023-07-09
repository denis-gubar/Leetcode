class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long result = total;
        int N = nums.size();
        vector<int> A(nums);
        for (int k = 1; k < N; ++k)
        {            
            for (int i = 0; i < N; ++i)
                if (A[(i + k) % N] > nums[i])
                {
                    total -= A[(i + k) % N];
                    total += nums[i];
                    A[(i + k) % N] = nums[i];
                }
            total += x;
            result = min(result, total);
        }
        return result;
    }
};
