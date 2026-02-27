class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int const N = nums.size();
        vector<int> A{ 0, 0 };
        for (int i = 0, pos = 0; i < N; ++i)
        {
            if (nums[i] % 2 == 1)
                pos = 1 - pos;
            if (i % 6 == 5)
                pos = 1 - pos;
            A[pos] += nums[i];
        }
        return A[0] - A[1];
    }
};
