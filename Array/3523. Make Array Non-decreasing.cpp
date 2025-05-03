class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int const N = nums.size();
        int result = 0;
        int HWM = N;
        vector<pair<int, int>> P(N);
        for (int i = 0; i < N; ++i)
            P[i] = { nums[i], i };
        sort(P.begin(), P.end());
        while (!P.empty())
        {
            if (P.back().second < HWM)
                ++result, HWM = P.back().second;
            P.pop_back();
        }
        return result;
    }
};
