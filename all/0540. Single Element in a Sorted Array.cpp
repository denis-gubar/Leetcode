class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size();
        int a = 0, b = N - 1;
        while(a + 1 < b)
        {
            int m = (a + b) / 2;
            if (nums[m] == nums[m + 1])
            {
                if (m % 2 == 0)
                    a = m;
                else
                    b = m;
            }
            else
            {
                if (m % 2 == 0)
                    b = m;
                else
                    a = m;
            }
        }
        if (a % 2 == 0)
            return nums[a];
        return nums[b];
    }
};