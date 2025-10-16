class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        int N = nums.size();
        while (nums.back() > 0)
        {
            for(int i = 0; i < N; ++i)
                if (nums[i] > 0)
                {
                    int x = nums[i];
                    for (int j = i; j < N; ++j)
                        nums[j] -= x;
                    ++result;
                }
            sort(nums.begin(), nums.end());
        }
        return result;
    }
};
