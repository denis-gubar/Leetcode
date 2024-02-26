class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int result = 1;
        int x = nums[0] + nums[1];
        int N = nums.size();
        for (int i = 2; i < N - 1; i += 2, ++result)
            if (nums[i] + nums[i + 1] != x)
                break;
        return result;
    }
};
