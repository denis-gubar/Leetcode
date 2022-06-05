class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1)
        {
            int N = nums.size();
            vector<int> A(N / 2);
            for (int i = 0; i < N / 2; ++i)
            {
                if (i % 2 == 0)
                    A[i] = min(nums[2 * i], nums[2 * i + 1]);
                else
                    A[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
            nums = move(A);
        }
        return nums[0];
    }
};
