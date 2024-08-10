class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int N = nums.size();
        for(int R = 0; R < N; ++R)
        {
            int V = R;
            int x = 0;
            while ((nums[V] > 0) == nums[(V + nums[V] + N * 1'000) % N] > 0)
            {                    
                V = (V + nums[V] + N * 1'000) % N;
                if (++x == N)
                    break;
            }
            if (V != (V + nums[V] + N * 1'000) % N &&
                (nums[V] > 0) == nums[(V + nums[V] + N * 1'000) % N] > 0)
                return true;
        }
        return false;
    }
};
