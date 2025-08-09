class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int const N = nums.size();
        for (int p = 1; p < N; ++p)
        {
            if (!(nums[p] > nums[p - 1]))
                break;
            for (int q = p + 1; q < N - 1; ++q)
            {
                if (!(nums[q] < nums[q - 1]))
                    break;
                bool flag = true;
                for (int i = q + 1; flag && i < N; ++i)
                    flag = nums[i] > nums[i - 1];
                if (flag)
                    return true;
            }
        }
        return false;
    }
};
