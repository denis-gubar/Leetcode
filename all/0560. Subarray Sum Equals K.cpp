class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> M;
        int sum = 0;
        for(int n: nums)
        {
            sum += n;
            if (sum == k)
                ++result;
            if (M.find(sum - k) != M.end())
                result += M[sum - k];
            ++M[sum];
        }
        return result;
    }
};