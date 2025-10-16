class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        auto calc = [](int x)
            {
                string result;
                while (x)
                    result += '0' + x % 2, x /= 2;
                reverse(result.begin(), result.end());
                return result;
            };
        do
        {
            string s = calc(nums[0]) + calc(nums[1]) + calc(nums[2]);
            int x = 0;
            for (char c : s)
                x = x * 2 + (c - '0');
            result = max(result, x);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }
};
