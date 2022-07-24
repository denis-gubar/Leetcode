class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] == 1)
            return 0;
        int M = numsDivide.size();
        int k = numsDivide[0];
        for (int x : numsDivide)
            k = gcd(k, x);

        for (int i = 0; i < N;)
        {
            if (k % nums[i] == 0)
                return i;

            int j = i;
            while(j < N && nums[i] == nums[j])
                ++j;
            i = j;
        }
        return -1;
    }
};
