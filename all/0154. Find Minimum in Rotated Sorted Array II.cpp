class Solution {
public:
    int findMin(vector<int>& nums) {        
        int a = 0, b = nums.size() - 1;
        while(a < b)
        {
            int m = a + (b - a) / 2;
            if (nums[m] < nums[b])
                b = m;
            else if (nums[m] > nums[b])
                a = m + 1;
            else
                --b;
        }
        return nums[a];
    }
};