class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int const N = nums.size();
        auto comp = [&nums, N](int a, int b) -> bool
            {
                if (a == -1 || a == N)
                    return true;
                if (b == -1 || b == N)
                    return false;
                return nums[a] < nums[b];
            };
        int a = -1, b = N;
        while (a + 2 < b)
        {
            int delta = max(1, (b - a) / 3);
            int c = a + delta;
            int d = b - delta;
            if (comp(a, c) && comp(d, c))
                b = d;
            else
                a = c;
        }
        return a + 1;
    }
};
