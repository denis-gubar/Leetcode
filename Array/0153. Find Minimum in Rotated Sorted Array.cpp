class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size();
        int A = 0, B = N - 1;
        if (nums[A] < nums[B])
            return nums[A];
        while(B - A > 1)
        {
            int X = (A + B) / 2;
            if (nums[A] > nums[X])
                B = X;
            else
                A = X;
        }
        return nums[B];
    }
};