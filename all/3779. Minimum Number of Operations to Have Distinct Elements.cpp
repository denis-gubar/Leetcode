class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        int a = 0, b = 0, nonDistinctCount = 0;
        unordered_map<int, int> M;
        for (int x : nums)
            if (++M[x] == 2)
                ++nonDistinctCount;
        if (nonDistinctCount == 0)
            return result;
        while (nums.size() % 3)
            nums.push_back(-1);
        for (int i = 0; i < N; i += 3)
        {
            ++result;
            if (--M[nums[i]] == 1)
            {
                --nonDistinctCount;
                if (nonDistinctCount == 0)
                    break;
            }
            if (--M[nums[i + 1]] == 1)
            {
                --nonDistinctCount;
                if (nonDistinctCount == 0)
                    break;
            }
            if (--M[nums[i + 2]] == 1)
            {
                --nonDistinctCount;
                if (nonDistinctCount == 0)
                    break;
            }
        }
        return result;
    }
};
