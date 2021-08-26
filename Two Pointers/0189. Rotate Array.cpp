class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        if (nums.empty() || k % N == 0)
            return;
        k %= N;
        k = N - k;
        int rotateCount = 0, start = 0, position = 0, save = nums[start];
        while(true)
        {
            ++rotateCount;
            int nextPosition = (position + k) % N;
            if (nextPosition != start)
            {
                nums[position] = nums[nextPosition];
                position = nextPosition;
            }
            else
            {
                nums[position] = save;
                if (rotateCount == N)
                    break;
                ++start; save = nums[start];
                position = start;
            }
            
        }
    }
};