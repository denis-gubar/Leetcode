class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int N = nums.size(), D = divisors.size();
        int result = 1 << 30, score = 0;
        for (int i = 0; i < D; ++i)
        {
            int current = 0;
            for (int j = 0; j < N; ++j)
                if (nums[j] % divisors[i] == 0)
                    ++current;
            if (current == score)
                result = min(result, divisors[i]);
            else if (current > score)
                score = current, result = divisors[i];
        }
        return result;
    }
};
