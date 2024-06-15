class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long result = 0;
        int prev = -1;
        int count = 0;
        for (int x : nums)
        {
            if (x == prev)
            {
                result += 1LL * count * (count + 1) / 2;
                count = 0;
            }
            prev = x;
            ++count;
        }
        result += 1LL * count * (count + 1) / 2;
        return result;
    }
};
