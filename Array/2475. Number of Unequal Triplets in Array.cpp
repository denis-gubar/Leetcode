class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int result = 0;
        int N = nums.size();
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (nums[i] != nums[j])
                    for (int k = j + 1; k < N; ++k)
                        result += (nums[i] != nums[k] && nums[j] != nums[k]);
        return result;
    }
};
