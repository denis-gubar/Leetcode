class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long result = 0;
        int last = nums.back();
        while (!nums.empty())
        {
            int current = nums.back();
            nums.pop_back();
            int delta = (current + last - 1) / last;
            result += delta - 1;
            last = current / delta;
        }
        return result;
    }
};
