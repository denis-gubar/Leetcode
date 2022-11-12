class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int N = nums.size();
        constexpr int INF = 1'000'000;
        for (int& x : nums)
            x += 1'000;
        target += 3'000;
        sort(nums.begin(), nums.end());
        vector<int> A(6'001, INF), B(6'001, INF);
        for (int i = 0; i < N; ++i)
            if (A[nums[i]] == INF)
                A[nums[i]] = i;
        for (int k = 0; k < 2; ++k)
        {
            A.swap(B);
            A.assign(6'001, INF);
            for (int x = 0; x < 6'001; ++x)
                for (int i = B[x] + 1; i < N; ++i)
                {
                    int sum = x + nums[i];
                    if (A[sum] > i)
                        A[sum] = i;
                }
        }
        int result = INF;
        for (int x = 0; x < 6'001; ++x)
            if (A[x] != INF && abs(result - target) > abs(x - target))
                result = x;                
        return result - 3'000;
    }
};
