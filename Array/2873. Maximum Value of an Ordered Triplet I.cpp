class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        int N = nums.size();
        for(int i = 0; i < N; ++i)
            for(int j = i + 1; j < N; ++j)
                for(int k = j + 1; k < N; ++k)
                    result = max(result, (1LL * nums[i] - nums[j]) * nums[k]);
        return result;
    }
};
