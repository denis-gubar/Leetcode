class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long result = 0;
        nums.insert(nums.begin(), 0);
        int N = nums.size();
        nums.push_back(0);
        long long current = 0;
        for (int i = N - 1; i >= 0; --i)
        {
            if (nums[i] <= nums[i + 1])
                current += nums[i];
            else
            {
                if (nums[i] <= current)
                    current += nums[i];
                else
                    current = nums[i];
            }
            result = max(result, current);
        }
        return result;
    }
};
