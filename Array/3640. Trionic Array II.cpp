class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long const INF = -(1LL << 60);
        long long result = INF;
        nums.push_back(-(1 << 30));
        int const N = nums.size();
        int sign = 0, last = 0;
        vector<pair<long long, long long>> P;
        P.reserve(N);
        for (int i = 1; i < N; ++i)
        {
            if (sign != -1 && nums[i] > nums[i - 1])
            {
                sign = 1;
                continue;
            }
            if (sign != 1 && nums[i] < nums[i - 1])
            {
                sign = -1;
                continue;
            }
            if (sign == 0)
            {
                last = i;
                continue;
            }
            if (last < i)
            {
                if (sign == 1)
                {
                    long long maxPrefix = nums[last] + nums[last + 1], sum = maxPrefix;
                    for (int j = last + 2; j < i; ++j)
                        sum += nums[j], maxPrefix = max(maxPrefix, sum);
                    long long maxSuffix = nums[i - 1] + nums[i - 2];
                    sum = maxSuffix;
                    for (int j = i - 3; j >= last; --j)
                        sum += nums[j], maxSuffix = max(maxSuffix, sum);
                    P.push_back({ maxPrefix, maxSuffix });
                }
                else
                {
                    long long sum = 0;
                    for (int j = last + 1; j < i - 1; ++j)
                        sum += nums[j];
                    P.push_back({ INF, sum });
                }
            }
            last = i, sign = 0;
            if (nums[i - 1] < nums[i])
                sign = 1, --last;
            if (nums[i - 1] > nums[i])
                sign = -1, --last;
        }
        int const M = P.size();
        for (int i = 1; i < M - 1; ++i)
        {
            if (P[i - 1].first != INF && P[i].first == INF && P[i + 1].first != INF)
                result = max(result, P[i - 1].second + P[i].second + P[i + 1].first);
        }
        return result;
    }
};
