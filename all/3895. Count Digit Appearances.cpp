class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int result = 0;
        for (int x : nums)
        {
            string t = to_string(x);
            result += count(t.begin(), t.end(), '0' + digit);
        }
        return result;
    }
};
