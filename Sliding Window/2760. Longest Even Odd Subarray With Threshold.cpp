class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int result = 0;
        int N = nums.size();
        for(int start = 0; start < N; ++start)
            if (nums[start] % 2 == 0 && nums[start] <= threshold)
            {
                int R = start;
                while (R + 1 < N && nums[R + 1] <= threshold && nums[R] % 2 != nums[R + 1] % 2)
                    ++R;
                result = max(result, R - start + 1);
            }
        return result;
    }
};
