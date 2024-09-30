class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int const N = nums.size();
        nth_element(nums.begin(), nums.begin() + N / 2, nums.end());
        int median = nums[N / 2];
        auto F = [&nums, N](int x) -> int&
            {
                return nums[(2 * x + 1) % (N | 1)];
            };
        int i = 0, a = 0, b = N - 1;
        while(i <= b)
            if (F(i) > median)
            {
                swap(F(i), F(a));
                ++a; ++i;
            }
            else if (F(i) < median)
            {
                swap(F(i), F(b));
                --b;
            }
            else
            {
                ++i;
            }
    }
};
