class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        int result = 0;
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        for (auto [key, value] : M)
        {
            if (value == 1)
                return -1;
            result += (value + 2) / 3;
        }
        return result;
    }
};
