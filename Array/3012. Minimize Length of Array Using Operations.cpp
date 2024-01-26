class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int b = N - 1;
        while (b > 0)
        {
            if (nums[0] == nums[b])
                break;
            if (nums[b] % nums[0] > 0 && nums[b] % nums[0] < nums[0])
                nums[0] = nums[b] % nums[0];
            --b;
        }
        return (b + 2) / 2;
    }
};
