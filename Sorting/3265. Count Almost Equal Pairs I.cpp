class Solution {
public:
    int countPairs(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        auto calc = [](int x)
            {
                vector<int> result(7);
                int pos = 0;
                while (x > 0)
                {
                    result[pos] = x % 10;
                    x /= 10;
                    ++pos;
                }
                return result;
            };
        for (int i = 0; i < N; ++i)
        {
            auto A = calc(nums[i]);
            for (int j = i + 1; j < N; ++j)
            {
                if (nums[j] == nums[i])
                {
                    ++result;
                    continue;
                }
                auto B = calc(nums[j]);
                int pos = 0;
                int count = 0;
                for (int a = 0; a < 7; ++a)
                    for (int b = a; b < 7; ++b)
                    {
                        swap(B[a], B[b]);
                        result += A == B;
                        swap(B[a], B[b]);
                    }
            }
        }
        return result;
    }
};
