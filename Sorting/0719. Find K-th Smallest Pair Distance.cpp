class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int const N = nums.size();
        int a = nums.back() - nums[0], b = nums.back() - nums[0] + 1;
        for (int i = 1; i < N; ++i)
            a = min(a, nums[i] - nums[i - 1]);
        map<int, int> M;
        auto calc = [&nums, &M, N](int m) -> int
            {
                int realM = 0;
                int result = 0;
                int left = 0, right = 0;
                while (right < N && nums[right] - nums[0] < m)
                    realM = nums[right] - nums[0], result += right, ++right;
                for(; right < N; ++right)
                {
                    while (left < N && nums[right] - nums[left] > m)
                        ++left;
                    realM = max(realM, nums[right] - nums[left]);
                    result += right - left;
                }
                M[realM] = result;
                return result;
            };
        calc(nums.back() - nums[0]);
        calc(a);
        int result = -1;
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            int const x = calc(m);
            if (x <= k)
                a = m;
            else
                b = m, result = b;
        }
        for (auto [key, value] : M)
        {
            result = key;
            if (value >= k)
                break;
        }
        return result;
    }
};
