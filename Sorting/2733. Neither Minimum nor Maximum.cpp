class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int a = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());
        for (int x : nums)
            if (x != a && x != b)
                return x;
        return -1;
    }
};
