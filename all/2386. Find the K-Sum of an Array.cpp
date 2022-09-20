class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int N = nums.size();
        long long result = 0;
        sort(nums.begin(), nums.end(), [](int a, int b)
            {
                return abs(a) < abs(b);
            });
        long long totalB = 0, totalA = 0;
        for (int i = 0; i < N; ++i)
        {
            if (nums[i] > 0)
                totalB += nums[i];
            else if (nums[i] < 0)
                totalA += nums[i];
        }
        multiset<long long> S;
        S.insert(totalB); S.insert(totalA);
        for (int i = 0; i < N; ++i)
        {
            auto it = prev(S.end());
            vector<long long> Q;
            long long minS = *S.begin();
            if (nums[i] >= 0)
            {
                while (*it - nums[i] >= minS)
                {
                    Q.push_back(*it - nums[i]);
                    if (it == S.begin())
                        break;
                    --it;
                }
            }
            else
            {
                while (*it + nums[i] >= minS)
                {
                    Q.push_back(*it + nums[i]);
                    if (it == S.begin())
                        break;
                    --it;
                }
            }
            S.insert(Q.begin(), Q.end());
            while (S.size() > k)
                S.erase(S.begin());
        }
        return *S.begin();
    }
};
