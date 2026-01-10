class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int D) {
        int result = 0;
        int const N = nums.size();
        unordered_map<int, int> M;
        for (int j = 0; j < N; ++j)
        {
            for (int k = j + 1; k < N; ++k)
                result += M[(D - (nums[j] + nums[k]) % D) % D];
            ++M[nums[j] % D];
        }
        return result;
    }
};
