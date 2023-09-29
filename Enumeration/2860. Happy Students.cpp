class Solution {
public:
    int countWays(vector<int>& nums) {
        int result = 0;
        int N = nums.size();
        sort(nums.begin(), nums.end());        
        for (int x = 0; x <= N; ++x)
        {
            auto it1 = lower_bound(nums.begin(), nums.end(), x);
            auto it2 = upper_bound(nums.begin(), nums.end(), x);
            int A = it1 - nums.begin();
            int B = nums.end() - it2;
            if (A + B == N && A == x)
                ++result;
        }
        return result;
    }
};
