class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int N = nums.size();
        int MAX = nums[0];
        vector<long long> conv(N);
        for (int i = 0; i < N; ++i)
        {
            MAX = max(MAX, nums[i]);
            conv[i] = nums[i] + MAX;
        }
        vector<long long> result(N);
        for (int i = 0; i < N; ++i)
            result[i] = (i > 0 ? result[i - 1] : 0) + conv[i];
        return result; 
    }
};
