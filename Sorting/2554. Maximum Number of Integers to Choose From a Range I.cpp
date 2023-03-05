class Solution {
public:
    int maxCount(vector<int>& banned, int N, int maxSum) {
        unordered_set<int> S(banned.begin(), banned.end());
        int result = 0;
        for (int k = 1; k <= N; ++k)
        {            
            if (maxSum - k < 0)
                return result;
            if (S.find(k) == S.end())
            {
                maxSum -= k;
                ++result;
            }
        }
        return result;
    }
};
