class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int result = 0;
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int a = 0, b = N - 1;
        while (a < b)
        {
            if (nums[a] + nums[b] == k)
                ++result, ++a, --b;
            else if (nums[a] + nums[b] < k)
                ++a;
            else
                --b;
        }
        return result;
    }
};
