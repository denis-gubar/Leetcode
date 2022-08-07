class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int N = nums.size();
        nums.push_back(-1);
        nums.push_back(-2);
        vector<bool> F(N + 3);
        F[0] = true;
        for(int i = 0; i < N; ++i)
            if (F[i])
            {
                if (nums[i] == nums[i + 1])
                    F[i + 2] = true;
                if (nums[i] == nums[i + 1] && nums[i] == nums[i + 2])
                    F[i + 3] = true;
                if (nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1)
                    F[i + 3] = true;
            }
        return F[N];
    }
};
