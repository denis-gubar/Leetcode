class Solution {
public:
    int minimizeMax(vector<int>& nums, int P) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int a = -1, b = nums.back();
        auto calc = [&nums, P, N](int m) -> bool
        {
            int count = 0;
            for (int i = 0; i < N - 1; ++i)
                if (nums[i + 1] - nums[i] <= m)
                    ++count, ++i;
            return count >= P;
        };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
