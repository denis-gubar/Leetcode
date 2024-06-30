static vector<int> F;
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        F.reserve(110'000);
        for (int x = 0; x < 10; ++x)
            F.push_back(x);
        for (int prefix = 1; prefix < 10'000; ++prefix)
        {
            int rest = prefix;
            int suffix = 0, k = 1;
            while (rest > 0)
            {
                suffix = suffix * 10 + rest % 10;
                rest /= 10;
                k *= 10;
            }
            F.push_back(prefix * k + suffix);
            for (int d = 0; d < 10; ++d)
                F.push_back(k * (prefix * 10 + d) + suffix);
        }
        sort(F.begin(), F.end());
    }
}
class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        init();        
        int N = nums.size();
        nth_element(nums.begin(), nums.begin() + N / 2, nums.end());
        auto it = lower_bound(F.begin(), F.end(), nums[N / 2]);
        long long a = *it, b = *prev(it);
        long long A = 0, B = 0;
        for (int x : nums)
            A += abs(a - x), B += abs(b - x);
        return min(A, B);
    }
};
