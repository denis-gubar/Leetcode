class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(N - 1);
        for(int i = 1; i < N; ++i)
            result[i - 1] = nums[i - 1] | nums[i];
        return result;
    }
};