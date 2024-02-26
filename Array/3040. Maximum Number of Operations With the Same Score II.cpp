static int F[2'000][2'000];
class Solution {
public:
    vector<int> nums;
    int N;
    int calc(int x, int a, int b)
    {
        if (a >= b)
            return 0;
        int& result = F[a][b];
        if (result == -1)
        {
            result = 0;
            if (nums[a] + nums[a + 1] == x)
                result = max(result, 1 + calc(x, a + 2, b));
            if (nums[b] + nums[b - 1] == x)
                result = max(result, 1 + calc(x, a, b - 2));
            if (nums[a] + nums[b] == x)
                result = max(result, 1 + calc(x, a + 1, b - 1));
        }
        return result;
    }
    int maxOperations(vector<int>& nums) {
        this->nums = nums;
        N = nums.size();
        int x = nums[0] + nums[1];
        x = nums[0] + nums[N - 1];
        x = nums[N - 2] + nums[N - 1];
        int result = 0;
        memset(F, -1, sizeof(F));
        result = max(result, calc(nums[0] + nums[1], 0, N - 1));
        memset(F, -1, sizeof(F));
        result = max(result, calc(nums[0] + nums[N - 1], 0, N - 1));
        memset(F, -1, sizeof(F));
        result = max(result, calc(nums[N - 2] + nums[N - 1], 0, N - 1));
        return result;
    }
};
