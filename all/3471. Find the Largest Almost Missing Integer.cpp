class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int const N = nums.size();
        if (N == k)
            return *max_element(nums.begin(), nums.end());
        for (int result = 50; result >= 0; --result)
            if (find(nums.begin(), nums.end(), result) != nums.end())
            {
                int count = 0;
                for (int i = 0; i + k <= N; ++i)
                    for (int j = i; j < i + k; ++j)
                        count += nums[j] == result;
                if (count == 1)
                    return result;
            }
        return -1;
    }
};
