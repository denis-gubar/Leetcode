class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> S;
        int sum = 0;
        int prev = -1;
        for(int n: nums)
        {
            n %= k;
            sum = (sum + n) % k;
            if (n == 0)
            {
                if (prev == 0)
                    return true;
                if (!S.empty() && sum == 0)
                    return true;
            }
            else if (!S.insert(sum).second)
                return true;
            if (S.size() > 1 && sum == 0)
                return true;
            prev = n;
        }
        return false;
    }
};