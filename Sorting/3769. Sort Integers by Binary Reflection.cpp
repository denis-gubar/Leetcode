class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b)
            {
                auto calc = [](int x)
                    {
                        int result = 0;
                        while(x > 0)
                        {
                            result = result * 2 + x % 2;
                            x /= 2;
                        }
                        return result;
                    };
                if (calc(a) != calc(b))
                    return calc(a) < calc(b);
                return a < b;
            });
        return nums;
    }
};
