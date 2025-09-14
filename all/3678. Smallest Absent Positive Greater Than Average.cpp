class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int const N = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        for (int result = 1; ; ++result)
            if (result * N > total && find(nums.begin(), nums.end(), result) == nums.end())
                return result;
        return -1;
    }
};
