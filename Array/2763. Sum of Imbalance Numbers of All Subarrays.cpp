class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int N = nums.size();
        int result = 0;
        for (int start = 0; start < N; ++start)
        {
            set<int> S;
            int balance = 0;
            for (int last = start; last < N; ++last)
            {
                if (auto P = S.insert(nums[last]); P.second)
                {
                    if (P.first != S.begin() && nums[last] - *prev(P.first) == 1)
                        ++balance;
                    if (next(P.first) != S.end() && *next(P.first) - nums[last] == 1)
                        ++balance;
                }
                result += S.size() - 1 - balance;
            }
        }
        return result;
    }
};
