class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int N = nums.size();
        int result = 0;
        for (int i = 0; i < N; ++i)
        {
            int d1 = to_string(nums[i])[0] - '0';
            for (int j = i + 1; j < N; ++j)
            {
                int d2 = to_string(nums[j]).back() - '0';
                if (gcd(d1, d2) == 1)
                    ++result;
            }
        }            
        return result;
    }
};
