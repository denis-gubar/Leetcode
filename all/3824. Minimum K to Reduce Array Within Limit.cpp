class Solution {
public:
    int minimumK(vector<int>& nums) {
        int const N = nums.size();
        long long a = 0, b = 1LL << 30;
        auto calc = [&nums](long long m) -> bool
            {
                long long count = 0;
                for (int x : nums)
                    count += (x + m - 1) / m;
                return count <= m * m;
            };
        while(a + 1 < b)
        {
            long long m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
