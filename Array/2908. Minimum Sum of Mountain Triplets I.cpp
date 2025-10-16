class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int result = -1;
        int N = nums.size();
        for(int i = 0; i < N; ++i)
            for(int j = i + 1; j < N; ++j)
                if (nums[i] < nums[j])
                    for(int k = j + 1; k < N; ++k)
                        if (nums[k] < nums[j])
                        {
                            int sum = nums[i] + nums[j] + nums[k];
                            if (result == -1 || result > sum)
                                result = sum;
                        }
        return result;                    
    }
};
