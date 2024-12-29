class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int const N = nums.size();
        int result = (N + 2) / 3;
        unordered_set<int> S;
        for (int i = N / 3 * 3; i < N; ++i)
            S.insert(nums[i]);
        if (S.size() < N % 3)
            return (N + 2) / 3;
        result -= N % 3 > 0;
        int x = N % 3;
        for (int i = N / 3 * 3 - 3; i >= 0; i -= 3, x += 3)
        {
            for (int j = i, k = 0; k < 3; ++j, ++k)
                S.insert(nums[j]);
            if (S.size() == x + 3)
                --result;
            else
                break;
        }
        return result;
    }
};
