class Solution {
public:
    int findDuplicate( vector<int>& nums ) {
        int n = nums.size();
        int a = 1, b = n - 1;
        while (a < b)
        {
            int median = (a + b) / 2;
            int x = median - a + 1, y = b - median;
            int lo = 0, hi = 0;
            for (const auto& i : nums)
            {
                lo += (a <= i && i <= median);
                hi += (median < i && i <= b);
            }
            if (lo > x || hi < y)
                b = median;
            else
                a = median + 1;                
        }
        return a;
    }
};